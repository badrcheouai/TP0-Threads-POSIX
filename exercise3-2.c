#include <stdio.h>
#include <pthread.h>

pthread_t threadA, threadB, threadC, threadD;


void* threadCFunction(void* arg) {
    printf("Thread C started\n");
    printf("Thread C finished\n");
    return NULL;
}


void* threadAFunction(void* arg) {
    printf("Thread A started\n");
    pthread_create(&threadC, NULL, threadCFunction, NULL);
    pthread_join(threadC, NULL);
    printf("Thread A finished\n");
    return NULL;
}

void* threadBFunction(void* arg) {
    printf("Thread B started\n");
    printf("Thread B finished\n");
    return NULL;
}



void* threadDFunction(void* arg) {
    printf("Thread D started\n");
    pthread_create(&threadB, NULL, threadBFunction, NULL);
    pthread_join(threadB, NULL);
    printf("Thread D finished\n");
    return NULL;
}

int main() {
    printf("Main thread started\n");
    pthread_create(&threadA, NULL, threadAFunction, NULL);
    pthread_create(&threadD, NULL, threadDFunction, NULL);
    pthread_join(threadA, NULL);
    pthread_join(threadD, NULL);
    printf("Main thread finished\n");
    return 0;
}