#include <stdio.h>

int main() {
    int frames[10], pages[30], n, f, i, j, k = 0, flag, faults = 0;

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
        flag = 0;
        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            frames[k] = pages[i];
            k = (k + 1) % f;
            faults++;
        }

        printf("Frames: ");
        for (j = 0; j < f; j++)
            if (frames[j] != -1) printf("%d ", frames[j]);
        printf("\n");
    }

    printf("Page Faults = %d\n", faults);
    printf("Page Hits = %d\n", n - faults);
    return 0;
}

