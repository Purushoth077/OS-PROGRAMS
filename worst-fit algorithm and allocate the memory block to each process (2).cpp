#include <stdio.h>

#define MAX_PARTITIONS 100
#define MAX_PROCESSES 100

void worstFit(int partitions[], int numPartitions, int processes[], int numProcesses) {
    int i, j;
    int allocation[MAX_PROCESSES];

    // Initialize allocation array to -1 (indicating unallocated)
    for (i = 0; i < numProcesses; i++) {
        allocation[i] = -1;
    }

    // Iterate through each process
    for (i = 0; i < numProcesses; i++) {
        int worstIndex = -1;
        int worstSize = -1;

        // Find the worst-fit partition for the current process
        for (j = 0; j < numPartitions; j++) {
            if (processes[i] <= partitions[j] && partitions[j] > worstSize) {
                worstIndex = j;
                worstSize = partitions[j];
            }
        }

        // Allocate the process to the worst-fit partition
        if (worstIndex != -1) {
            allocation[i] = worstIndex;
            partitions[worstIndex] -= processes[i];
        }
    }

    // Print the allocation details
    printf("Process\tSize\tPartition\n");
    for (i = 0; i < numProcesses; i++) {
        printf("%d\t%d\t", i+1, processes[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int partitions[MAX_PARTITIONS] = {40, 10, 30, 60};
    int numPartitions = 4;
    int processes[MAX_PROCESSES] = {100, 50, 30, 120, 35};
    int numProcesses = 5;

    printf("Memory Partitions: ");
    for (int i = 0; i < numPartitions; i++) {
        printf("%d KB ", partitions[i]);
    }
    printf("\n");

    printf("Processes: ");
    for (int i = 0; i < numProcesses; i++) {
        printf("%d KB ", processes[i]);
    }
    printf("\n");

    worstFit(partitions, numPartitions, processes, numProcesses);

    return 0;
}
