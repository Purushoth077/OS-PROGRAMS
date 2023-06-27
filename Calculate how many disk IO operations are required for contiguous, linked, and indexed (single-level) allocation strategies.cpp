#include <stdio.h>

// Constants
#define BLOCK_SIZE 1
#define FCB_IN_MEMORY 0
#define INDEX_BLOCK_IN_MEMORY 0
#define TOTAL_BLOCKS 100

// Function to calculate disk I/O operations for contiguous allocation
int contiguousAllocation(int blockNumber) {
    if (blockNumber == 1) {
        if (FCB_IN_MEMORY)
            return 0;
        else
            return 1;
    } else if (blockNumber <= TOTAL_BLOCKS) {
        if (INDEX_BLOCK_IN_MEMORY)
            return 0;
        else
            return 1;
    } else {
        return -1; // Invalid block number
    }
}

// Function to calculate disk I/O operations for linked allocation
int linkedAllocation(int blockNumber) {
    if (blockNumber == 1) {
        if (FCB_IN_MEMORY)
            return 0;
        else
            return 1;
    } else if (blockNumber <= TOTAL_BLOCKS) {
        if (blockNumber == TOTAL_BLOCKS)
            return 1;
        else
            return 2;
    } else {
        return -1; // Invalid block number
    }
}

// Function to calculate disk I/O operations for indexed allocation
int indexedAllocation(int blockNumber) {
    if (blockNumber == 1) {
        if (FCB_IN_MEMORY)
            return 0;
        else
            return 1;
    } else if (blockNumber <= TOTAL_BLOCKS) {
        if (blockNumber == TOTAL_BLOCKS)
            return 2;
        else
            return 2;
    } else {
        return -1; // Invalid block number
    }
}

int main() {
    int blockNumber;

    // Test Case: Block added at the beginning
    printf("Adding block at the beginning:\n");
    blockNumber = 1;
    printf("Contiguous allocation: %d disk I/O operations\n", contiguousAllocation(blockNumber));
    printf("Linked allocation: %d disk I/O operations\n", linkedAllocation(blockNumber));
    printf("Indexed allocation: %d disk I/O operations\n\n", indexedAllocation(blockNumber));

    // Test Case: Block added in the middle
    printf("Adding block in the middle:\n");
    blockNumber = 50;
    printf("Contiguous allocation: %d disk I/O operations\n", contiguousAllocation(blockNumber));
    printf("Linked allocation: %d disk I/O operations\n", linkedAllocation(blockNumber));
    printf("Indexed allocation: %d disk I/O operations\n\n", indexedAllocation(blockNumber));

    // Test Case: Block added at the end
    printf("Adding block at the end:\n");
    blockNumber = 100;
    printf("Contiguous allocation: %d disk I/O operations\n", contiguousAllocation(blockNumber));
    printf("Linked allocation: %d disk I/O operations\n", linkedAllocation(blockNumber));
    printf("Indexed allocation: %d disk I/O operations\n", indexedAllocation(blockNumber));

    return 0;
}
