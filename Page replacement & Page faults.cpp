#include <stdio.h>
#define MAX_FRAMES 3
#define MAX_PAGES 22
int main() {
    int pageFrames[MAX_FRAMES];
    int pageReference[MAX_PAGES] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int pageFaults = 0;
    for (int i = 0; i < MAX_FRAMES; i++) {
        pageFrames[i] = -1;
    }

    for (int i = 0; i < MAX_PAGES; i++) {
        int page = pageReference[i];
        int found = 0;
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (pageFrames[j] == page) {
                found = 1;
                break;
            }
        }
        if (!found) {
            int replaceIndex = 0;
            int longestFutureTime = -1;
            for (int j = 0; j < MAX_FRAMES; j++) {
                int futureTime = MAX_PAGES;
                for (int k = i + 1; k < MAX_PAGES; k++) {
                    if (pageFrames[j] == pageReference[k]) {
                        futureTime = k - i;
                        break;
                    }
                }
                if (futureTime > longestFutureTime) {
                    longestFutureTime = futureTime;
                    replaceIndex = j;
                }
            }
            pageFrames[replaceIndex] = page;
            pageFaults++;
        }
        printf("Page Reference: %d\tPage Frames: ", page);
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (pageFrames[j] == -1) {
                printf("- ");
            } else {
                printf("%d ", pageFrames[j]);
            }
        }
        printf("\n");
    }
    printf("\nTotal Page Faults: %d\n", pageFaults);

    return 0;
}
