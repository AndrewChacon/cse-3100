/* Compile using cc shmp2.c -o shmp2 -lrt -lpthread */

#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main() {
	const char* zone = "/memzone1";
	int md = shm_open(zone, O_RDWR, S_IRWXU);

	void* ptr = mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_SHARED, md, 0);
	if(ptr==MAP_FAILED) {
		printf("mmap failure: %s\n", strerror(errno));
		exit(1);
	}
	char* buf = ptr;

	/* TODO: Get access to the semaphore "/sema1". 
			 If a line has been read by the first process, print it on stdout. Else, wait. Do not use the wait call to do this! 
			 Destroy the shared memory map and semaphore once you are done. */

	return 0;
}
