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

double calculateAverageHeadMovement(int tracks[], int numTracks, int head, int direction) {
    int totalHeadMovement = 0;
    int currentPosition = head;

    // Sort the tracks array in ascending order
    qsort(tracks, numTracks, sizeof(int), compare);

    int index = 0;
    while (index < numTracks && tracks[index] < currentPosition) {
        index++;
    }

    int i = index;
    if (direction == 0) {
        while (i >= 0) {
            totalHeadMovement += absDiff(currentPosition, tracks[i]);
            currentPosition = tracks[i];
            i--;
        }

        i = index + 1;
        if (i < numTracks) {
            totalHeadMovement += absDiff(currentPosition, tracks[i]);
            currentPosition = tracks[i];
            i++;
        }
    } else {
        while (i < numTracks) {
            totalHeadMovement += absDiff(currentPosition, tracks[i]);
            currentPosition = tracks[i];
            i++;
        }

        i = index - 1;
        if (i >= 0) {
            totalHeadMovement += absDiff(currentPosition, tracks[i]);
            currentPosition = tracks[i];
            i--;
        }
    }

    return (double)totalHeadMovement / numTracks;
}

int main() {
    int tracks[MAX_TRACKS] = {55, 58, 60, 70, 18};
    int numTracks = 5;
    int head;
    int direction;

    printf("Enter the initial position of the head: ");
    scanf("%d", &head);

    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &direction);

    double averageHeadMovement = calculateAverageHeadMovement(tracks, numTracks, head, direction);

    printf("Average head movement: %.2lf\n", averageHeadMovement);

    return 0;
}
