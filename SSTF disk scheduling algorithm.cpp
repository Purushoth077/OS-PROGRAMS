#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TRACKS 100

int absDiff(int a, int b) {
    return abs(a - b);
}

int findClosestTrack(int tracks[], int numTracks, int head) {
    int closestTrack = -1;
    int minDiff = INT_MAX;

    for (int i = 0; i < numTracks; i++) {
        int diff = absDiff(tracks[i], head);
        if (diff < minDiff) {
            minDiff = diff;
            closestTrack = tracks[i];
        }
    }

    return closestTrack;
}

double calculateAverageHeadMovement(int tracks[], int numTracks, int head) {
    double totalHeadMovement = 0;
    int currentPosition = head;

    for (int i = 0; i < numTracks; i++) {
        int closestTrack = findClosestTrack(tracks, numTracks, currentPosition);
        totalHeadMovement += absDiff(currentPosition, closestTrack);
        currentPosition = closestTrack;
        tracks[currentPosition] = -1; // Mark the track as visited
    }

    return totalHeadMovement / numTracks;
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
