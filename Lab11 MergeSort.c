#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int l, int m, int r) {
    int i = l, j = m+1, k = 0, t[r - l + 1]; //i(left half), j(right half), k(temp index), t(temp array)
    while (i <= m && j <= r)
        t[k++] = (a[i] < a[j]) ? a[i++] : a[j++]; // Pick smaller element
    while (i <= m) t[k++] = a[i++];  // Copy remaining left
    while (j <= r) t[k++] = a[j++];  // Copy remaining right
    for (i = l, k = 0; i <= r; i++) a[i] = t[k++]; // Copy back
}

void mergeSort(int a[], int l, int r) {
    if (l >= r) return;                      // Base case
    int m = (l + r) / 2;
    mergeSort(a, l, m);                      // Sort left
    mergeSort(a, m + 1, r);                  // Sort right
    merge(a, l, m, r);                       // Merge halves
}

int main() {
    FILE *f = fopen("Lab11.dat", "w");
    srand(time(NULL));
    for (int n = 5000; n <= 25000; n += 5000) {
        int *a = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) a[i] = rand();
        clock_t start = clock();
        mergeSort(a, 0, n-1);
        clock_t end = clock();
        fprintf(f, "%d\t%.2f\n", n, (double)(end - start) * 1000 / CLOCKS_PER_SEC);
        free(a);
    }
    fclose(f);
    printf("Time Complexity: O(n log n)\n");
    return 0;
}
