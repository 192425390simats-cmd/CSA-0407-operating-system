#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5
sem_t chopstick[N];

void *philosopher(void *num) {
    int i = *(int *)num;
    sem_wait(&chopstick[i]);
    sem_wait(&chopstick[(i+1)%N]);

    printf("Philosopher %d is eating\n", i+1);
    sleep(1);

    sem_post(&chopstick[i]);
    sem_post(&chopstick[(i+1)%N]);
    printf("Philosopher %d finished eating\n", i+1);
    return NULL;
}

int main() {
    pthread_t t[N];
    int i, a[N];

    for (i = 0; i < N; i++)
        sem_init(&chopstick[i], 0, 1);

    for (i = 0; i < N; i++) {
        a[i] = i;
        pthread_create(&t[i], NULL, philosopher, &a[i]);
    }

    for (i = 0; i < N; i++)
        pthread_join(t[i], NULL);

    return 0;
}

