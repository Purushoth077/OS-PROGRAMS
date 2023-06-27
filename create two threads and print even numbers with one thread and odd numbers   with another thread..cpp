#include <stdio.h>
#include <pthread.h>

void *printEvenNumbers(void *arg) {
    int i;
    for (i = 2; i <= 20; i += 2) {
        printf("Even Thread: %d\n", i);
    }
    pthread_exit(NULL);
}

void *printOddNumbers(void *arg) {
    int i;
    for (i = 1; i <= 19; i += 2) {
        printf("Odd Thread: %d\n", i);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t evenThread, oddThread;

    // Create the even thread
    if (pthread_create(&evenThread, NULL, printEvenNumbers, NULL) != 0) {
        printf("Failed to create even thread.\n");
        return 1;
    }

    // Create the odd thread
    if (pthread_create(&oddThread, NULL, printOddNumbers, NULL) != 0) {
        printf("Failed to create odd thread.\n");
        return 1;
    }

    // Wait for the threads to finish
    pthread_join(evenThread, NULL);
    pthread_join(oddThread, NULL);

    return 0;
}
