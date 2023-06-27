#include <stdio.h>

#define MAX_PARTITIONS 5

typedef struct {
    int id;
    int size;
    int allocated;
} Process;

typedef struct {
    int id;
    int size;
} Partition;

void firstFit(Process processes[], int numProcesses, Partition partitions[], int numPartitions) {
    int i, j;

    for (i = 0; i < numProcesses; i++) {
        for (j = 0; j < numPartitions; j++) {
            if (partitions[j].size >= processes[i].size && !processes[i].allocated) {
                partitions[j].size -= processes[i].size;
                processes[i].allocated = 1;
                printf("Process %d (Size: %d KB) is allocated to Partition %d.\n",
                       processes[i].id, processes[i].size, partitions[j].id);
                break;
            }
        }

        if (!processes[i].allocated) {
            printf("Process %d (Size: %d KB) cannot be allocated.\n", processes[i].id, processes[i].size);
        }
    }
}

int main() {
    Partition partitions[MAX_PARTITIONS] = {
        {1, 40}, {2, 10}, {3, 30}, {4, 60}
    };

    Process processes[5] = {
        {1, 100, 0}, {2, 50, 0}, {3, 30, 0}, {4, 120, 0}, {5, 35, 0}
    };

    printf("Memory Partitions:\n");
    for (int i = 0; i < MAX_PARTITIONS; i++) {
        printf("Partition %d (Size: %d KB)\n", partitions[i].id, partitions[i].size);
    }

    printf("\n");

    firstFit(processes, 5, partitions, MAX_PARTITIONS);

    return 0;
}
