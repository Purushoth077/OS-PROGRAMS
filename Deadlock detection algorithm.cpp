#include <stdio.h>
#include <stdlib.h>

#define NUM_PROCESSES 3
#define NUM_RESOURCES 3

int main() {
    int max[NUM_PROCESSES][NUM_RESOURCES] = {{3, 6, 8}, {4, 3, 3}, {3, 4, 4}};
    int allocation[NUM_PROCESSES][NUM_RESOURCES] = {{3, 3, 3}, {2, 0, 3}, {1, 2, 4}};
    int available[NUM_RESOURCES] = {1, 2, 0};
    int finish[NUM_PROCESSES] = {0};
    int need[NUM_PROCESSES][NUM_RESOURCES];
    for (int i = 0; i < NUM_PROCESSES; i++) {
        for (int j = 0; j < NUM_RESOURCES; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    int work[NUM_RESOURCES];
    for (int i = 0; i < NUM_RESOURCES; i++) {
        work[i] = available[i];
    }
    int count = 0;
    while (count < NUM_PROCESSES) {
        int found = 0;
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < NUM_RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == NUM_RESOURCES) {
                    for (int k = 0; k < NUM_RESOURCES; k++) {
                        work[k] += allocation[i][k];
                    }
                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }
        if (!found) {
            printf("Deadlock detected!\n");
            printf("Deadlocked processes: ");
            for (int i = 0; i < NUM_PROCESSES; i++) {
                if (!finish[i]) {
                    printf("%d ", i);
                }
            }
            printf("\n");
            exit(0);
        }
    }
    printf("No deadlock detected.\n");
    return 0;
}
