#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TRACKS 9

int main() {
    int tracks[MAX_TRACKS] = {55, 58, 60, 70, 18, 90, 150, 160, 184};
    int headPosition, totalHeadMovement = 0;
    float averageHeadMovement;

    printf("Enter the initial head position: ");
    scanf("%d", &headPosition);

    printf("Head Movement:\n");
    printf("--------------\n");
    printf("%d", headPosition);

    for(int i = 0; i < MAX_TRACKS; i++) {
        int distance = abs(headPosition - tracks[i]);
        totalHeadMovement += distance;
        headPosition = tracks[i];
        printf(" -> %d", headPosition);
    }

    printf("\n--------------\n");

    averageHeadMovement = (float)totalHeadMovement / MAX_TRACKS;
    printf("Average Head Movement: %.2f\n", averageHeadMovement);

    return 0;
}
