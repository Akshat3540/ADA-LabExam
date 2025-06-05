#include <stdio.h>
int a[10][10], n, i, j, k;
int min(int x, int y) { return x < y ? x : y; }
int main() {
    printf("Number of vertices:");
    scanf("%d", &n);
    printf("Cost Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
    printf("Shortest path\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}
