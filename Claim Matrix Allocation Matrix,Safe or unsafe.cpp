#include <stdio.h>
#include <stdbool.h>

#define NUM_PROCESSES 4
#define NUM_RESOURCES 3

int claim[NUM_PROCESSES][NUM_RESOURCES] = {
    {3, 2, 2},
    {6, 1, 3},
    {3, 1, 4},
    {4, 2, 2}
};

int allocation[NUM_PROCESSES][NUM_RESOURCES] = {
    {1, 0, 0},
    {6, 1, 2},
    {2, 1, 1},
    {0, 0, 2}
};

int available[NUM_RESOURCES] = {9, 3, 6};

bool finish[NUM_PROCESSES] = {false};

int main() {
    int work[NUM_RESOURCES];
    int need[NUM_PROCESSES][NUM_RESOURCES];
    int i, j, k;
    for (i = 0; i < NUM_PROCESSES; i++) {
        for (j = 0; j < NUM_RESOURCES; j++) {
            need[i][j] = claim[i][j] - allocation[i][j];
        }
    }
    for (i = 0; i < NUM_RESOURCES; i++) {
        work[i] = available[i];
    }
    int safe_sequence[NUM_PROCESSES];
    int count = 0;
    bool found;
    while (count < NUM_PROCESSES) {
        found = false;
        for (i = 0; i < NUM_PROCESSES; i++) {
            if (!finish[i]) {
                for (j = 0; j < NUM_RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == NUM_RESOURCES) {
                    // Process i can finish
                    for (k = 0; k < NUM_RESOURCES; k++) {
                        work[k] += allocation[i][k];
                    }
                    finish[i] = true;
                    safe_sequence[count] = i;
                    count++;
                    found = true;
                }
            }
        }
        if (!found) {
            break;
        }
    }

    if (count == NUM_PROCESSES) {
        printf("Safe sequence: ");
        for (i = 0; i < NUM_PROCESSES; i++) {
            printf("%d ", safe_sequence[i]);
        }
        printf("\n");
        return 0;
    } else {
        printf("System is in an unsafe state.\n");
        return 1;
    }
}
