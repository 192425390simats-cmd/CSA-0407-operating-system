#include <stdio.h>

int main() {
    int n, m, i, j, k;
    n = 3; m = 3;
    int alloc[3][3] = { {1,2,2}, {1,0,3}, {1,2,1} };
    int max[3][3] = { {3,3,2}, {1,2,3}, {1,3,5} };
    int avail[3] = {2,1,0};
    int f[n], ans[n], ind = 0;
    int need[n][m];

    for (i = 0; i < n; i++) {
        f[i] = 0;
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    ans[ind++] = i;
                    for (j = 0; j < m; j++)
                        avail[j] += alloc[i][j];
                    f[i] = 1;
                }
            }
        }
    }

    printf("Safe Sequence: ");
    for (i = 0; i < n - 1; i++)
        printf("P%d -> ", ans[i]);
    printf("P%d\n", ans[n - 1]);

    return 0;
}

