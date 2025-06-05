#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++)
            if (a[j] < a[min]) min = j;
        int t = a[i]; a[i] = a[min]; a[min] = t;
    }
}

int main() {
    FILE *f = fopen("Lab9.dat", "w");
    srand(time(NULL));
    for (int n = 5000; n <= 25000; n += 5000) {
        int *a = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) a[i] = rand();
        clock_t start = clock();
        selectionSort(a, n);
        clock_t end = clock();
        fprintf(f, "%d\t%.2f\n", n, (double)(end - start) * 1000 / CLOCKS_PER_SEC);
        free(a);
    }
    fclose(f);
    printf("Time Complexity: O(n^2)\n");
    return 0;
}
