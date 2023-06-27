#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TRACKS 100

int absDiff(int a, int b) {
    return abs(a - b);
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

double calculateAverageHeadMovement(int tracks[], int numTracks, int head) {
    int totalHeadMovement = 0;
    int currentPosition = head;

    // Sort the tracks array in ascending order
    qsort(tracks, numTracks, sizeof(int), compare);

    int index = 0;
    while (index < numTracks && tracks[index] < currentPosition) {
        index++;
    }

    int i = index;
    while (i < numTracks) {
        totalHeadMovement += absDiff(currentPosition, tracks[i]);
        currentPosition = tracks[i];
        i++;
    }

    // Move the head to the beginning of the tracks
    totalHeadMovement += absDiff(currentPosition, tracks[0]);
    currentPosition = tracks[0];

    i = 1;
    while (i < index) {
        totalHeadMovement += absDiff(currentPosition, tracks[i]);
        currentPosition = tracks[i];
        i++;
    }

    return (double)totalHeadMovement / numTracks;
}

int main() {
    int tracks[MAX_TRACKS] = {55, 58, 60, 70, 18};
    int numTracks = 5;
    int head;

    printf("Enter the initial position of the head: ");
    scanf("%d", &head);

    double averageHeadMovement = calculateAverageHeadMovement(tracks, numTracks, head);

    printf("Average head movement: %.2lf\n", averageHeadMovement);

    return 0;
}
