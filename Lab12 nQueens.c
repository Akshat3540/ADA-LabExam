#include <stdio.h>

int n, x[10], count;

int Abs(int x) {
    return x < 0 ? -x : x;
}

int place(int k, int i) {
    for (int j = 1; j < k; j++)
        if (x[j] == i || Abs(x[j] - i) == Abs(j - k))
            return 0;
    return 1;
}

int nQueens(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n) {
                printf("Solution %d: ", ++count);
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++)
                        printf("%c", j == x[i] ? 'Q' : 'X');
                    printf("\n");
            }
            } else
                nQueens(k + 1, n);
        }
    }
    return count;
}

int main() {
    printf("Enter the size of the chessboard: ");
    scanf("%d", &n);
    printf("\n The number of possibilities are %d\n", nQueens(1, n));
    return 0;
}
