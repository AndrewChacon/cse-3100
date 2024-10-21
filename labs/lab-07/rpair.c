#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <string.h>
#include <errno.h>
#include <math.h>

long createSamples(unsigned wID, long nbSamples, double d) {
    long ttl = 0;
    unsigned seed = wID;

    for (long i = 0; i < nbSamples; ++i) {
        double x = rand_r(&seed) / (double)RAND_MAX;
        double y = rand_r(&seed) / (double)RAND_MAX;

        if (fabs(x - y) < d) {
            ttl++;
        }
    }
    return ttl;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("usage: rpair <d> <samples> <workers>\n");
        exit(1);
    }

    double d = atof(argv[1]);
    long s = atol(argv[2]);
    int nbW = atoi(argv[3]);

    int shm_fd = shm_open("/event_count", O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(long));
    long *shared_ttl = mmap(NULL, sizeof(long), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    *shared_ttl = 0;

    pid_t pids[nbW];

    long base_trials = s / nbW;
    long extra_trials = s % nbW;

    for (int i = 0; i < nbW; ++i) {
        pids[i] = fork();
        if (pids[i] < 0) {
            perror("fork");
            exit(1);
        } else if (pids[i] == 0) {
            long trials = base_trials + (i < extra_trials ? 1 : 0);
            long events = createSamples(i, trials, d);

            *shared_ttl += events;

            exit(0);
        }
    }

    for (int i = 0; i < nbW; ++i) {
        wait(NULL);
    }

    long total_events = *shared_ttl;
    double probability = (double)total_events / s;

    printf("Total trials = %ld \t Total events = %ld \t Probability = %lf\n", s, total_events, probability);

    munmap(shared_ttl, sizeof(long));
    shm_unlink("/event_count");

    return 0;
}
