#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, seek = 0, req[20];

    printf("Requests: ");
    scanf("%d",&n);

    for(i=0;i<n;i++) scanf("%d",&req[i]);

    printf("Head: ");
    scanf("%d",&head);

    for(i=0;i<n;i++) {
        seek += abs(req[i] - head);
        head = req[i];
    }

    printf("Total Seek Time = %d\n", seek);
    printf("Average Seek Time = %.2f\n", (float)seek/n);

    return 0;
}

