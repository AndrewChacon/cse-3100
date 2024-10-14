#include "analyze.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void analyzeURL(char* url, char* host, int* port, char* doc) {
    char* start = url;

    if (strncmp(url, "http://", 7) == 0) {
        start += 7;
    } else if (strncmp(url, "https://", 8) == 0) {
        start += 8;
    }

    char* colon_pos = strchr(start, ':');
    char* slash_pos = strchr(start, '/');
    
    if (colon_pos && (!slash_pos || colon_pos < slash_pos)) {
        strncpy(host, start, colon_pos - start);
        host[colon_pos - start] = '\0';

        *port = atoi(colon_pos + 1);
    } else {
        *port = 80;

        if (slash_pos) {
            strncpy(host, start, slash_pos - start);
            host[slash_pos - start] = '\0';
        } else {
            strcpy(host, start);
        }
    }

    if (slash_pos) {
        strcpy(doc, slash_pos);
    } else {
        strcpy(doc, "/");
    }
}
