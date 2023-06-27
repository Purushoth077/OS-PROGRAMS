#include <stdio.h>

#define MAX_PARTITIONS 10

int main() {
    int partitions[MAX_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int num_partitions = 6;
    int processes[] = {115, 500, 358, 200, 375};
    int num_processes = 5;
    int i, j, allocated_partition_index;
    int allocation[num_partitions];
    for (i = 0; i < num_partitions; i++) {
        allocation[i] = -1;
    }
    for (i = 0; i < num_processes; i++) {
        allocated_partition_index = -1;
        for (j = 0; j < num_partitions; j++) {
            if (allocation[j] == -1 && processes[i] <= partitions[j]) {
                allocated_partition_index = j;
                break;
            }
        }
        if (allocated_partition_index != -1) {
            allocation[allocated_partition_index] = i;
            printf("Process %d of size %d KB allocated to partition %d of size %d KB\n", i+1, processes[i], allocated_partition_index+1, partitions[allocated_partition_index]);
        } else {
            printf("Process %d of size %d KB cannot be allocated\n", i+1, processes[i]);
        }
    }

    return 0;
}
