#include <stdio.h>
int cost[10][10], n, colsum[10], select[10], i, j, k;

void compColsum() {
    for (j = 0; j < n; j++) {
        colsum[j] = 0;
        for (i = 0; i < n; i++) colsum[j] += cost[i][j];
    }
}

void tpSort() {
    printf("Topological ordering is:\n");
    for (i = 0; i < n; i++) {
        compColsum();
        for (j = 0; j < n && (!select[j] || colsum[j]); j++);
        if (j == n) break;
        printf("%d ", j);
        select[j] = 1;
        for (k = 0; k < n; k++) cost[j][k] = 0;
    }
    printf("\n");
}

int main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    tpSort();
    return 0;
}
