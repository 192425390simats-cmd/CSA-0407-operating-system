#include <stdio.h>
#include <string.h>

struct File {
    char name[20];
    int start;
    int length;
};

int main() {
    struct File f[10];
    int n, i, j;

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter file name: ");
        scanf("%s", f[i].name);
        printf("Enter starting block: ");
        scanf("%d", &f[i].start);
        printf("Enter length (number of blocks): ");
        scanf("%d", &f[i].length);
    }

    printf("\nFile Allocation Table:\n");
    printf("File\tStart\tLength\tBlocks\n");

    for (i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t", f[i].name, f[i].start, f[i].length);
        for (j = 0; j < f[i].length; j++) {
            printf("%d ", f[i].start + j);
        }
        printf("\n");
    }

    return 0;
}

