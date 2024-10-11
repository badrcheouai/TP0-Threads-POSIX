#include <stdio.h>
#include <string.h>
#include <pthread.h>

char login[100];
char password[100];

void* saisir(void* arg) {
    printf("Login: ");
    scanf("%s", login);
    printf("Password: ");
    scanf("%s", password);
    return NULL;
}

void* inverser(void* arg) {
    int len = strlen(login);
    for (int i = 0; i < len / 2; i++) {
        char temp = login[i];
        login[i] = login[len - i - 1];
        login[len - i - 1] = temp;
    }
    return NULL;
}

void* afficher(void* arg) {
    if (strcmp(login, password) == 0) {
        printf("Authentification successful\n");
    } else {
        printf("Authentification failed\n");
    }
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, saisir, NULL);
    pthread_join(t1, NULL);

    pthread_create(&t2, NULL, inverser, NULL);
    pthread_join(t2, NULL);

    pthread_create(&t3, NULL, afficher, NULL);
    pthread_join(t3, NULL);

    return 0;
}