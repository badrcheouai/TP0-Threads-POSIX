#include <stdio.h>
#include <pthread.h>

void* afficherPairs(void* arg) {
    for (int i = 0; i <= 10; i += 2) {
        printf("Pair: %d\n", i);
    }
    return NULL;
}

void* afficherImpairs(void* arg) {
    for (int i = 1; i < 10; i += 2) {
        printf("Impair: %d\n", i);
    }
    return NULL;
}

int main() {
    pthread_t threadPair, threadImpair;

    pthread_create(&threadPair, NULL, afficherPairs, NULL);
    pthread_create(&threadImpair, NULL, afficherImpairs, NULL);

    pthread_join(threadPair, NULL);
    pthread_join(threadImpair, NULL);

    return 0;
}