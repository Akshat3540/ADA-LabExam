#include <stdio.h>
int w[10], x[10], n, m, count;
void subset(int s, int k, int r) {
    x[k] = 1;
    if (s + w[k] == m) {
        printf("subset %d: ", ++count);
        for (int i = 0; i <= k; i++)
            if (x[i]) printf("%d ", w[i]);
        printf("\n");
    }
    else if (k < n - 1 && s + w[k] + w[k+1] <= m)
        subset(s + w[k], k + 1, r - w[k]);
    if (k < n - 1 && s + r - w[k] >= m && s + w[k+1] <= m) {
        x[k] = 0;
        subset(s, k + 1, r - w[k]);
    }
}
int main() {
    int sum = 0;
    printf("\nEnter the n value:");
    scanf("%d", &n);
    printf("\nEnter the set in increasing order:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        sum += w[i];
    }
    printf("Enter the sum :");
    scanf("%d", &m);
    if (sum < m || w[0] > m)
        printf("No Subset possible\n");
    else
        subset(0, 0, sum);
    return 0;
}