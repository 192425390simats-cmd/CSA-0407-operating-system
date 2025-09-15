#include <stdio.h>

int findOptimal(int pages[], int n, int frame[], int fn, int index) {
    int farthest = index, pos = -1;
    int i, j;
    for (i = 0; i < fn; i++) {
        for (j = index; j < n; j++) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if (j == n)  /* not found in future */
            return i;
    }
    return (pos == -1) ? 0 : pos;
}

int main() {
    int pages[30], frame[10];
    int n, fn, faults = 0, fcount = 0;
    int i, j, found, pos;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &fn);

    for (i = 0; i < fn; i++)
        frame[i] = -1;

    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < fn; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            if (fcount < fn) {
                frame[fcount++] = pages[i];
            } else {
                pos = findOptimal(pages, n, frame, fn, i + 1);
                frame[pos] = pages[i];
            }
            faults++;
        }

        printf("\nPage %d -> ", pages[i]);
        for (j = 0; j < fn; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
    }

    printf("\n\nTotal Page Faults = %d\n", faults);
    return 0;
}

