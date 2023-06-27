#include <stdio.h>
#include <stdbool.h>

#define NUM_BLOCKS 16
#define INODE_BLOCKS 8
#define FILE_BLOCKS (NUM_BLOCKS - INODE_BLOCKS)
#define BLOCK_SIZE 1024
#define MIN_FILE_SIZE 1024

void initializeFileSystem(bool allocatedBlocks[]) {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        allocatedBlocks[i] = false;
    }
}

bool allocateBlocks(bool allocatedBlocks[], int startBlock, int numBlocks) {
    for (int i = startBlock; i < startBlock + numBlocks; i++) {
        if (allocatedBlocks[i]) {
            return false; // Blocks are not available
        }
    }

    // Mark the blocks as allocated
    for (int i = startBlock; i < startBlock + numBlocks; i++) {
        allocatedBlocks[i] = true;
    }

    return true; // Blocks are successfully allocated
}

int main() {
    bool allocatedBlocks[NUM_BLOCKS];
    initializeFileSystem(allocatedBlocks);

    int startBlock, numBlocks;
    int fileSize;

    printf("Enter the start block: ");
    scanf("%d", &startBlock);

    if (startBlock < INODE_BLOCKS || startBlock >= NUM_BLOCKS) {
        printf("Invalid start block.\n");
        return 0;
    }

    printf("Enter the number of blocks required: ");
    scanf("%d", &numBlocks);

    if (numBlocks <= 0 || numBlocks > FILE_BLOCKS) {
        printf("Invalid number of blocks.\n");
        return 0;
    }

    printf("Enter the file size (in bytes): ");
    scanf("%d", &fileSize);

    if (fileSize < MIN_FILE_SIZE || fileSize > (BLOCK_SIZE * numBlocks)) {
        printf("Invalid file size.\n");
        return 0;
    }

    if (!allocateBlocks(allocatedBlocks, startBlock, numBlocks)) {
        printf("Blocks are not available.\n");
        return 0;
    }

    printf("File allocated successfully.\n");

    return 0;
}
