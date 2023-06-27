#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n = 5; // number of tracks
    int tracks[5] = {55, 58, 60, 70, 18}; // track positions
    int head_position = 50; // initial head position
    int direction = 1; // 1 for moving right, -1 for moving left
    int total_head_movement = 0;

    while (1) {
        // find the next track to access
        int next_track = -1;
        int i;
        for (i = 0; i < n; i++) {
            if (direction == 1 && tracks[i] >= head_position) {
                if (next_track == -1 || tracks[i] < tracks[next_track]) {
                    next_track = i;
                }
            } else if (direction == -1 && tracks[i] <= head_position) {
                if (next_track == -1 || tracks[i] > tracks[next_track]) {
                    next_track = i;
                }
            }
        }

        if (next_track == -1) {
            // if there are no more tracks to access in the current direction, reverse direction
            direction = -direction;
            continue;
        }

        // move the head to the next track
        int head_movement = abs(tracks[next_track] - head_position);
        total_head_movement += head_movement;
        head_position = tracks[next_track];

        // mark the current track as accessed
        tracks[next_track] = -1;

        // check if all tracks have been accessed
        int all_tracks_accessed = 1;
        for (i = 0; i < n; i++) {
            if (tracks[i] != -1) {
                all_tracks_accessed = 0;
                break;
            }
        }

        if (all_tracks_accessed) {
            break;
        }
    }

    // calculate and print the average head movement
    float average_head_movement = (float) total_head_movement / n;
    printf("Average head movement: %.2f\n", average_head_movement);

    return 0;
}
