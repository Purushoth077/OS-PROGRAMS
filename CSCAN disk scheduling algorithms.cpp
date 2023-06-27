#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TRACKS 100

int absDiff(int a, int b) {
    return abs(a - b);
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void cscan(int tracks[], int numTracks, int initialPosition) {
    int headMovement = 0;
    int i, j;

    // Sort the tracks in ascending order
    qsort(tracks, numTracks, sizeof(int), cmpfunc);

    // Find the index where the initial position is present or should be inserted
    int index = 0;
    while (index < numTracks && tracks[index] < initialPosition) {
        index++;
    }

    // Move towards the end (right) and calculate head movement
    for (i = index; i < numTracks; i++) {
        headMovement += absDiff(tracks[i], initialPosition);
        initialPosition = tracks[i];
    }

    // Move towards the beginning (left) and calculate head movement
    headMovement += absDiff(tracks[numTracks - 1], 0);

    for (i = 0; i < index; i++) {
        headMovement += absDiff(tracks[i], 0);
        initialPosition = tracks[i];
    }

    printf("Average head movement: %.2f\n", (float)headMovement / numTracks);
}

int main() {
    int tracks[MAX_TRACKS] = {55, 58, 60, 70, 18};
    int numTracks = 5;
    int initialPosition = 5;

    printf("Track Positions: ");
    for (int i = 0; i < numTracks; i++) {
        printf("%d ", tracks[i]);
    }
    printf("\n");

    cscan(tracks, numTracks, initialPosition);

    return 0;
}
