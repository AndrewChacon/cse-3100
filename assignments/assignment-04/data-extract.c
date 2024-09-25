#include <stdlib.h>
#include <stdio.h>

/* This function copies integers from file infp to file outfp. */
int copy_integers(FILE *outfp, FILE *infp, int start, int end)
{
    int value;
    
    for (int i = start; i <= end; i++) {
        if (fseek(infp, i * sizeof(int), SEEK_SET) != 0) {
            printf("Error seeking in input file\n");
            return -1;
        }
        
        // read int
        if (fread(&value, sizeof(int), 1, infp) != 1) {
            printf("Error reading from input file\n");
            return -1;
        }
        
        // write int
        if (fwrite(&value, sizeof(int), 1, outfp) != 1) {
            printf("Error writing to output file\n");
            return -1;
        }
    }
    
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 4) {
        printf("Usage: %s <input-filename> <output-filename> range [range ..]\n", argv[0]);
        return -1;
    }

    FILE *infp = fopen(argv[1], "rb");
    if (infp == NULL) {
        // error opening file 
        return -1;
    }

    FILE *outfp = fopen(argv[2], "wb");
    if (outfp == NULL) {
        // error opening output file
        fclose(infp);
        return -1;
    }


    for (int i=3; i<argc; i++) {
        int start, end;
        if (sscanf(argv[i], "%d-%d", &start, &end) != 2) {
            if (sscanf(argv[i], "%d", &start) != 1) {
		printf("Invalid range!\n");
		return -1;
	    } 
            end = start;
        }

        if (start < 0 || end < 0 || end < start) {
	  printf("Start and end must be >= 0 and start must be <= end\n");
	  return -1;
	}
        if (copy_integers(outfp, infp, start, end)) {
	  printf("copy_integers() returned an error.\n");
	  return -1;
	}
    } 

    /* TODO: Close the files. If the operations fail, return -1. */
    fclose(infp);
    fclose(outfp);
    return 0;
}
