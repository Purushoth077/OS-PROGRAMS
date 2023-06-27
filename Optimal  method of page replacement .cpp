#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

int getPageFaults(int pageFrames[], int numFrames, int pageReferences[], int numReferences) {
    int faults = 0;
    bool isPagePresent[MAX_FRAMES] = { false };

    for (int i = 0; i < numReferences; i++) {
        int page = pageReferences[i];

        if (!isPagePresent[page]) {
            int replaceIndex = -1;
            int farthestIndex = -1;

            // Find the page to be replaced
            for (int j = 0; j < numFrames; j++) {
                int k;
                for (k = i + 1; k < numReferences; k++) {
                    if (pageFrames[j] == pageReferences[k]) {
                        if (k > farthestIndex) {
                            farthestIndex = k;
                            replaceIndex = j;
                        }
                        break;
                    }
                }
                if (k == numReferences) {
                    replaceIndex = j;
                    break;
                }
            }

            // Replace the page
            pageFrames[replaceIndex] = page;
            isPagePresent[page] = true;
            faults++;
        }
    }

    return faults;
}

int main() {
    int pageFrames[MAX_FRAMES];
    int numFrames;
    int pageReferences[MAX_PAGES];
    int numReferences;

    printf("Enter the number of page frames: ");
    scanf("%d", &numFrames);

    printf("Enter the page reference sequence (separated by spaces): ");
    for (int i = 0; i < MAX_PAGES; i++) {
        scanf("%d", &pageReferences[i]);
        if (pageReferences[i] == -1) {
            numReferences = i;
            break;
        }
    }

    int pageFaults = getPageFaults(pageFrames, numFrames, pageReferences, numReferences);

    printf("Number of page faults: %d\n", pageFaults);

    return 0;
}
