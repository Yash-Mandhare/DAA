// Write a program to find minimum number of multiplications in Matrix Chain
// Multiplication.

#include <stdio.h>
#define MAX 10
#define INF 999999

int main() {
    int n, i, j, k, L, q;
    int p[MAX], m[MAX][MAX];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions (n+1 numbers):\n");
    for (i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    // Initialize diagonal to 0
    for (i = 1; i <= n; i++)
        m[i][i] = 0;

    // L is chain length
    for (L = 2; L <= n; L++) {
        for (i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INF;
            for (k = i; k < j; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    printf("Minimum number of multiplications: %d\n", m[1][n]);
    return 0;
}


// Enter number of matrices: 3
// Enter dimensions:
// 10 30 5 60

// Minimum number of multiplications: 4500
