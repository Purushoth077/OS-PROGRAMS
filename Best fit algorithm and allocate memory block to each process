#include <stdio.h>
#define MAX_PARTITIONS 6
#define MAX_PROCESSES 5
void bestFit(int partitions[], int m, int processes[], int n) {
    int allocation[MAX_PROCESSES];
    int i, j;
    for (i = 0; i < n; i++) {
        int bestIdx = -1;
        for (j = 0; j < m; j++) {
            if (partitions[j] >= processes[i]) {
                if (bestIdx == -1 || partitions[j] < partitions[bestIdx]) {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            partitions[bestIdx] -= processes[i];
        } else {
            allocation[i] = -1;
        }
    }
    printf("Process No.\tProcess Size\tPartition Index\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d KB\t\t", i+1, processes[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i]+1);
        } else {
            printf("Not Allocated\n");
        }
    }
}
int main() {
    int partitions[] = {300, 600, 350, 200, 750, 125};
    int processes[] = {115, 500, 358, 200, 375};
    int m = sizeof(partitions) / sizeof(partitions[0]);
    int n = sizeof(processes) / sizeof(processes[0]);
    printf("Memory Partitions:\n");
    for (int i = 0; i < m; i++) {
        printf("%d. %d KB\n", i+1, partitions[i]);
    }
    printf("\nProcess Sizes:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %d KB\n", i+1, processes[i]);
    }
    printf("\nAllocation:\n");
    bestFit(partitions, m, processes, n);
    return 0;
}
