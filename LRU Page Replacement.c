#include <stdio.h>

int findLRU(int time[], int n) {
    int i, min = time[0], pos = 0;
    for (i = 1; i < n; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int frames[10], pages[30], time[10];
    int n, f, i, j, pos, faults = 0, hits = 0, counter = 0, found;

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    for (i = 0; i < f; i++)
        frames[i] = -1;

    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                hits++;
                found = 1;
                break;
            }
        }
        if (found == 0) {
            for (j = 0; j < f; j++) {
                if (frames[j] == -1) {
                    counter++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    faults++;
                    found = 1;
                    break;
                }
            }
        }
        if (found == 0) {
            pos = findLRU(time, f);
            counter++;
            frames[pos] = pages[i];
            time[pos] = counter;
            faults++;
        }
        printf("Frames: ");
        for (j = 0; j < f; j++)
            if (frames[j] != -1) printf("%d ", frames[j]);
        printf("\n");
    }

    printf("Page Faults = %d\n", faults);
    printf("Page Hits = %d\n", hits);
    return 0;
}

