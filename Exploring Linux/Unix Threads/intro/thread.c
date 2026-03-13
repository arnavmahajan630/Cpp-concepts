#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void * routine() {
    pid_t id = gettid(); // gives the the KERNEL TID
    printf("Hello from routine thread %d\n", id);
    sleep(3);
}

int main(int argc, char * argv[]) {

    pthread_t t1, t2;
    void * (*func_ptr)(void *) = routine;
    pthread_create(&t1, NULL, func_ptr, NULL);
    pthread_create(&t2, NULL, func_ptr, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}