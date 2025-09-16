#include <stdio.h>

int main() {
    int block[10], process[10], nb, np, i, j;

    printf("Blocks: ");
    scanf("%d",&nb);
    for(i=0;i<nb;i++) scanf("%d",&block[i]);

    printf("Processes: ");
    scanf("%d",&np);
    for(i=0;i<np;i++) scanf("%d",&process[i]);

    for(i=0;i<np;i++) {
        for(j=0;j<nb;j++) {
            if(block[j] >= process[i]) {
                printf("P%d -> B%d\n", i+1, j+1);
                block[j] -= process[i];
                break;
            }
        }
        if(j==nb) printf("P%d -> Not Allocated\n", i+1);
    }
    return 0;
}

