#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_INSTANCES 4
#define NUM_PROCESSES 4

sem_t semaphore;

void* process(void* process_id) {
    int id = (int*)process_id;
    printf("Process P%d is waiting...\n", id);

    sem_wait(&semaphore);  // Wait operation

    printf("Process P%d has acquired the resource.\n", id);
    printf("Process P%d is releasing the resource.\n", id);

    sem_post(&semaphore);  // Signal operation

    printf("Process P%d has released the resource.\n", id);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_PROCESSES];
    int process_ids[NUM_PROCESSES] = {1, 2, 3, 4};

    sem_init(&semaphore, 0, NUM_INSTANCES);  // Initialize semaphore

    // Create threads for processes
    for (int i = 0; i < NUM_PROCESSES; i++) {
        pthread_create(&threads[i], NULL, process, &process_ids[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_PROCESSES; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore);  // Destroy semaphore

    return 0;
}
