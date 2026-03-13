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
    pthread_t t1;
    pthread_t t2;
    pthread_mutex_init(&mu, NULL); // initialize the mutex
    void *(* func_ptr)(void *) = routine;
    pthread_create(&t1, NULL, func_ptr, NULL);
    pthread_create(&t2, NULL, func_ptr, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // destroy the mutext
    pthread_mutex_destroy(&mu);

    // print result
    printf("The final count is: %d", count);

}