#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

void generateFibonacci(int n) {
    int first = 0, second = 1, next;

    printf("Fibonacci Series: ");
    printf("%d %d ", first, second);

    for (int i = 3; i <= n; i++) {
        next = first + second;
        printf("%d ", next);
        first = second;
        second = next;
    }

    printf("\n");
}

int main() {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        generateFibonacci(10);
    } else {
        // Parent process
        wait(&status);

        printf("Prime Numbers: ");
        for (int i = 2; i <= 20; i++) {
            if (isPrime(i)) {
                printf("%d ", i);
            }
        }

        printf("\n");
    }

    return 0;
}
