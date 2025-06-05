#include <stdio.h>
int n, m, p[10], w[10];
void greedyKnapsack() {
    float profit = 0, max = 0; int k;
    printf("\nItems included: ");
    for (int i = 0; i < n; i++) {
        max = 0;
        for (int j = 0; j < n; j++)
            if (p[j] && (float)p[j]/w[j] > max)
                max = (float)p[j]/w[j], k = j;
        if (w[k] <= m)
            printf("%d ", k), m -= w[k], profit += p[k], p[k] = 0;
        else break;
    }
    printf("\nDiscrete knapsack profit: %.2f", profit);
    printf("\nContinuous knapsack profit: %.2f\n", profit + (float)m/w[k]*p[k]);
}
void main() {
    printf("Number of items: "); scanf("%d", &n);
    printf("Weights: "); for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    printf("Prices: ");  for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    printf("Knapsack capacity: "); scanf("%d", &m);
    greedyKnapsack();
}
