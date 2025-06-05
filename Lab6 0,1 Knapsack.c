#include <stdio.h>

int n, m, w[10], p[10], dp[10][10];
int max(int a, int b) { return a > b ? a : b; }
void knapsack() {
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            if (w[i] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], p[i] + dp[i-1][j - w[i]]);
    printf("\nMax profit: %d\n", dp[n][m]);
    printf("\nItems included: ");
    while (n > 0) {
        if (dp[n][m] != dp[n-1][m]) {
            printf("%d ", n);
            m -= w[n];
        }
        n--;
    }
}
int main() {
    printf("Number of items: ");
    scanf("%d", &n);
    printf("Weight of items: ");
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    printf("Price of items: ");
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    printf("Knapsack capacity: ");
    scanf("%d", &m);
    knapsack();
    return 0;
}
