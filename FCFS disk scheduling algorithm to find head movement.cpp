#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_tracks = 5;
    int track_positions[] = {55, 58, 60, 70, 18};

    int initial_position;
    printf("Enter the initial position of the disk head: ");
    scanf("%d", &initial_position);

    int total_head_movement = 0;
    int current_position = initial_position;
    printf("Disk head movement:\n");
    for (int i = 0; i < num_tracks; i++) {
        int track = track_positions[i];
        int head_movement = abs(track - current_position);
        total_head_movement += head_movement;
        printf("%d -> %d\t Head movement: %d\n", current_position, track, head_movement);
        current_position = track;
    }

    float average_head_movement = (float) total_head_movement / num_tracks;
    printf("Average head movement: %.2f\n", average_head_movement);

    return 0;
}
