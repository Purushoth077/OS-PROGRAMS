#include <stdio.h>

#define MAX_PARTITIONS 6
#define MAX_PROCESSES 5
void worstFit(int partitions[], int processes[], int allocation[]) {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        int worstIndex = -1;
        for (int j = 0; j < MAX_PARTITIONS; j++) {
            if (allocation[j] == 0 && partitions[j] >= processes[i]) {
                if (worstIndex == -1 || partitions[j] > partitions[worstIndex]) {
                    worstIndex = j;
                }
            }
        }
        if (worstIndex != -1) {
            allocation[worstIndex] = processes[i];
        }
    }
}
void printAllocation(int partitions[], int processes[], int allocation[]) {
    printf("Process\t\tSize\t\tPartition\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("P%d\t\t%d KB\t\t", i+1, processes[i]);
        if (allocation[i] != 0) {
            printf("%d KB\n", allocation[i]);
        } else {
            printf("Not Allocated\n");
        }
    }
}
int main() {
    int partitions[MAX_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int processes[MAX_PROCESSES] = {115, 500, 358, 200, 375};
    int allocation[MAX_PARTITIONS] = {0};
    worstFit(partitions, processes, allocation);
    printAllocation(partitions, processes, allocation);
    return 0;
}
