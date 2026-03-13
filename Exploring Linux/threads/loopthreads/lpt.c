#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t mu; // create a mutex


void * routine(void * ) {
    for(int i=0; i < 1000000; ++i) {
        pthread_mutex_lock(&mu); // lock the count variable.
        count++;
        pthread_mutex_unlock(&mu);
    }
}

int main() {
    pthread_t arr[4];
    pthread_mutex_init(&mu, NULL); // initialize the mutex
    void *(* func_ptr)(void *) = routine;

    for(int i = 0; i < 4; ++i) {
        if(pthread_create(&arr[i], NULL, func_ptr, NULL) != 0) {
            perror("failed to create the thread\n");
            return 1;
        }
        printf("thread %d has started\n", i);
    }

    for(int i = 0; i < 4; ++i) {
        if(pthread_join(arr[i], NULL) != 0) {
            perror("failed to join the thread\n");
            return 2;
        }
        printf("thread %d has completed execution\n", i);
    }

    // destroy the mutext
    pthread_mutex_destroy(&mu);

    // print result
    printf("The final count is: %d\n", count);

}