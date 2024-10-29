losing safety - gaining flexibility and ease of use when it comes to sharing 

consider two threads each doing the following with cnt = 100

int x = 0;

void increase(int cnt) {
    int i;
    for(i = 0; i < cnt; i++) {
        x = x + 1;
    }
}

void increase(int cnt) {
    int i;
    for(i = 0; i < cnt; i++) {
        x = x + 1;
    }
}

2 threads exec this function increase
both threads counting too 100, x should be 200 

