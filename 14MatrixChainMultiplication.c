#include <stdio.h>
#include <limits.h>
int matrixChainOrder(int p[], int n) {
    int m[n][n];
    int i, j, k, L, q;
    for (i = 1; i < n; i++) {
        m[i][i] = 0;
    }
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }
    return m[1][n - 1];
}
int main() {
    int arr[] = {10, 50, 20, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum number of multiplications is %d\n", matrixChainOrder(arr, n));
    int cost_AB_C = (10 * 50 * 20) + (10 * 20 * 100);
    printf("Number of multiplications for non-optimal order (A * B) * C is %d\n", cost_AB_C);
    return 0;
}
