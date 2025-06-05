#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int a[], int l, int r) {
    if (l >= r) return;              // Base case: 0 or 1 element
    int i = l, j = r, p = a[(l + r) / 2];  // i,j pointers, pivot(middle element)
    while (i <= j) {
        while (a[i] < p) i++;       // Move i right while a[i] < pivot
        while (a[j] > p) j--;       // Move j left while a[j] > pivot
        if (i <= j) {               // Swap if i and j have not crossed
            int t = a[i]; a[i] = a[j]; a[j] = t;
            i++; j--;
        }
    }
    if (l < j) quickSort(a, l, j); // Recur on left sub-array
    if (i < r) quickSort(a, i, r); // Recur on right sub-array
}


int main() {
    FILE *f = fopen("Lab10.dat", "w");
    srand(time(NULL));
    for (int n = 5000; n <= 25000; n += 5000) {
        int *a = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) a[i] = rand();
        clock_t start = clock();
        quickSort(a, 0, n-1);
        clock_t end = clock();
        fprintf(f, "%d\t%.2f\n", n, (double)(end - start) * 1000 / CLOCKS_PER_SEC);
        free(a);
    }
    fclose(f);
    printf("Time Complexity: O(n log n)\n");
    return 0;
}
