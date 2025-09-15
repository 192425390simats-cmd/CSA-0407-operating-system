#include <stdio.h>
#include <pthread.h>

void* printMessage(void* arg) {
    int id = *((int*)arg);
    printf("Hello from Thread %d\n", id);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    pthread_create(&t1, NULL, printMessage, &id1);
    pthread_create(&t2, NULL, printMessage, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main program finished\n");
    return 0;
}

