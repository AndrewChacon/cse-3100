/* Compile using cc shmp1.c -o shmp1 -lrt -lpthread */

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

void readLine(int sz, char buf[sz]) {
	char ch = getchar();
	char *p = buf;
	while(ch!=EOF && ch!='\n' && sz-- > 0) {
		*p++ = ch;
		ch = getchar();
	}
	*p= 0; //null terminate the string
}

int main() {
	const char* zone = "/memzone1"; //name of the memory mapping
	int md = shm_open(zone, O_RDWR|O_CREAT,S_IRWXU); //create a shared memory object. return a fd for zone where we can read/write or create one
    ftruncate(md, 4096); //specify the size of the memory mapping - must be a multiple of the page size for the system	
	
	void* ptr = mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_SHARED, md,0); //map the zone to virtual address space
	if(ptr==MAP_FAILED) {
		printf("mmap failure: %s\n", strerror(errno));
		exit(1);
	}
	memset(ptr,0,4096);
	char* buf = ptr;

	/* TODO: Create a semaphore "/sema1". 
			 Read a line from stdin and copy it into the shared map. A helper function readLine has been provided to read a line from stdin. 
			 Signal the sempahore when you have read a line. Think about the initial state of the semaphore.
			 Destroy the shared memory map and semaphore once you are done. */
		
	// create semaphore and initalize it to zero
	sem_t *sema = sem_open("/sema1", O_CREAT, S_IRWXU, 0); 
    if (sema == SEM_FAILED) {
        printf("sem_open failure: %s\n", strerror(errno));
        munmap(ptr, 4096);
        shm_unlink(zone);
        exit(1);
    }

	// read new line from stdin, readLine is built in function 
	printf("Enter new line: ");
	readLine(4096, buf);

	// copy new line into shared map
	sem_post(sema);
	printf("New line was shared into memory map and semaphore was signaled.\n");

	// clean up step
	

	return 0;
}
