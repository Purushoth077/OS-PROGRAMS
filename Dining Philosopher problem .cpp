#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

int state[NUM_PHILOSOPHERS];
pthread_mutex_t forks[NUM_PHILOSOPHERS];
pthread_cond_t cond_vars[NUM_PHILOSOPHERS];

void *philosopher(void *arg);
void pickup_forks(int phil_index);
void return_forks(int phil_index);
int left_fork_index(int phil_index);
int right_fork_index(int phil_index);
int can_eat(int phil_index);

int main() {
    pthread_t threads[NUM_PHILOSOPHERS];
    int i;

    // Initialize mutex locks and condition variables
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        state[i] = THINKING;
        pthread_mutex_init(&forks[i], NULL);
        pthread_cond_init(&cond_vars[i], NULL);
    }

    // Create philosopher threads
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_create(&threads[i], NULL, philosopher, (void *) &i);
    }

    // Wait for philosopher threads to complete
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy mutex locks and condition variables
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
        pthread_cond_destroy(&cond_vars[i]);
    }

    return 0;
}

void *philosopher(void *arg) {
    int phil_index = *((int *) arg);
    while (1) {
        // Think
        printf("Philosopher %d is thinking\n", phil_index);
        sleep(1);

        // Pick up forks
        pickup_forks(phil_index);

        // Eat
        printf("Philosopher %d is eating\n", phil_index);
        sleep(1);

        // Return forks
        return_forks(phil_index);
    }
}

void pickup_forks(int phil_index) {
    pthread_mutex_lock(&forks[left_fork_index(phil_index)]);
    pthread_mutex_lock(&forks[right_fork_index(phil_index)]);

    while (!can_eat(phil_index)) {
        pthread_cond_wait(&cond_vars[phil_index], &forks[right_fork_index(phil_index)]);
    }

    state[phil_index] = EATING;
}

void return_forks(int phil_index) {
    pthread_mutex_unlock(&forks[left_fork_index(phil_index)]);
    pthread_mutex_unlock(&forks[right_fork_index(phil_index)]);

    state[phil_index] = THINKING;

    pthread_cond_signal(&cond_vars[left_fork_index(phil_index)]);
    pthread_cond_signal(&cond_vars[right_fork_index(phil_index)]);
}

int left_fork_index(int phil_index) {
    return phil_index;
}

int right_fork_index(int phil_index) {
    return (phil_index + 1) % NUM_PHILOSOPHERS;
}

int can_eat(int phil_index) {
    return state[phil_index] == HUNGRY &&
           state[left_fork_index(phil_index)] != EATING &&
           state[right_fork_index(phil_index)] != EATING;
}
