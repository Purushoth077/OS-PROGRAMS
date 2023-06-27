#include <stdio.h>

#define DISK_BLOCK_SIZE 8192
#define POINTER_SIZE 4
#define NUM_DIRECT_BLOCKS 12

int main() {
    int maxFileSize = 0;

    // Calculate the size of direct blocks
    maxFileSize += NUM_DIRECT_BLOCKS * DISK_BLOCK_SIZE;

    // Calculate the size of single indirect block
    maxFileSize += (DISK_BLOCK_SIZE / POINTER_SIZE) * DISK_BLOCK_SIZE;

    // Calculate the size of double indirect block
    maxFileSize += (DISK_BLOCK_SIZE / POINTER_SIZE) * (DISK_BLOCK_SIZE / POINTER_SIZE) * DISK_BLOCK_SIZE;

    // Calculate the size of triple indirect block
    maxFileSize += (DISK_BLOCK_SIZE / POINTER_SIZE) * (DISK_BLOCK_SIZE / POINTER_SIZE) * (DISK_BLOCK_SIZE / POINTER_SIZE) * DISK_BLOCK_SIZE;

    printf("Maximum file size: %d bytes\n", maxFileSize);
    return 0;
}
