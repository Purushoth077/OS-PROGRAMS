#include <stdio.h>

#define MAX_FRAMES 3

int main() {
    int page_frames[MAX_FRAMES] = {0};
    int page_faults = 0;

    int page_reference[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3};
    int num_pages = sizeof(page_reference) / sizeof(page_reference[0]);
    for (int i = 0; i < MAX_FRAMES; i++) {
        page_frames[i] = -1;
    }
    for (int i = 0; i < num_pages; i++) {
        int page = page_reference[i];
        int found = 0;
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (page_frames[j] == page) {
                found = 1;
                break;
            }
        }
        if (!found) {
            int lru_frame = 0;
            int lru_time = page_frames[0];

            for (int j = 1; j < MAX_FRAMES; j++) {
                if (page_frames[j] == -1) {
                    lru_frame = j;
                    break;
                }
                if (page_frames[j] < lru_time) {
                    lru_frame = j;
                    lru_time = page_frames[j];
                }
            }
            page_frames[lru_frame] = page;
            page_faults++;
        }
    }

    printf("Number of page faults: %d\n", page_faults);

    return 0;
}
