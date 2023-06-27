#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
int sharedData;
sem_t semaphore;
void* thread1(void* arg) {
    sem_wait(&semaphore);
    int doubledData = sharedData * 2;
    printf("Thread 1: Doubled Data: %d\n", doubledData);
    sem_post(&semaphore); 
    pthread_exit(NULL);
}
void* thread2(void* arg) {
    sem_wait(&semaphore); 
    int multipliedData = sharedData * 5;
    printf("Thread 2: Multiplied Data: %d\n", multipliedData);
    sem_post(&semaphore); 
    pthread_exit(NULL);
}
int main() {
    sharedData = 10; 
    sem_init(&semaphore, 0, 1); 
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, thread1, NULL);
    pthread_create(&tid2, NULL, thread2, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    sem_destroy(&semaphore); 
    return 0;
}
