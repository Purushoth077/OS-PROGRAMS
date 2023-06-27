#include <stdio.h>
#define NUM_PROCESSES 5
#define NUM_RESOURCES 3

void calculateNeedMatrix(int allocation[][NUM_RESOURCES], int max[][NUM_RESOURCES], int need[][NUM_RESOURCES], int available[]) {
    for (int i = 0; i < NUM_PROCESSES; i++) {
        for (int j = 0; j < NUM_RESOURCES; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}
int main() {
    int allocation[NUM_PROCESSES][NUM_RESOURCES] = {
        {1, 1, 2},
        {2, 1, 2},
        {3, 0, 1},
        {0, 2, 0},
        {1, 1, 2}
    };
    int max[NUM_PROCESSES][NUM_RESOURCES] = {
        {5, 4, 4},
        {4, 3, 3},
        {9, 1, 3},
        {8, 6, 4},
        {2, 2, 3}
    };
    int available[NUM_RESOURCES] = {3, 2, 1};
    int need[NUM_PROCESSES][NUM_RESOURCES];
    calculateNeedMatrix(allocation, max, need, available);
    printf("Need Matrix:\n");
    for (int i = 0; i < NUM_PROCESSES; i++) {
        for (int j = 0; j < NUM_RESOURCES; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    return 0;
}
