// Write a program to implement optimal binary search tree and also calculate the best-case
// complexity.

#include <stdio.h>
#define MAX 10
#define INF 9999

int main() {
    int n, i, j, k, r;
    int key[MAX], freq[MAX], cost[MAX][MAX];

    printf("Enter number of keys: ");
    scanf("%d", &n);

    printf("Enter keys (in sorted order):\n");
    for (i = 0; i < n; i++)
        scanf("%d", &key[i]);

    printf("Enter frequencies:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &freq[i]);

    // Initialize cost for single keys
    for (i = 0; i < n; i++)
        cost[i][i] = freq[i];

    // DP for length > 1
    for (r = 1; r < n; r++) {
        for (i = 0; i < n - r; i++) {
            j = i + r;
            cost[i][j] = INF;
            int sum = 0;
            for (k = i; k <= j; k++)
                sum += freq[k];
            for (k = i; k <= j; k++) {
                int c = ((k > i) ? cost[i][k - 1] : 0) + ((k < j) ? cost[k + 1][j] : 0);
                if (c + sum < cost[i][j])
                    cost[i][j] = c + sum;
            }
        }
    }

    // Best case: Optimal minimum cost
    int bestCost = cost[0][n - 1];

    // Worst case: Linear BST (like linked list)
    int worstCost = 0;
    for (i = 0; i < n; i++)
        worstCost += freq[i] * (i + 1); // each key at depth i+1

    printf("\nMinimum cost of Optimal BST (Best Case): %d\n", bestCost);
    printf("Worst Case Cost (Skewed Tree): %d\n", worstCost);

    return 0;
}


// Enter number of keys: 3
// Enter keys:
// 10 20 30
// Enter frequencies:
// 34 8 50


// Minimum cost of Optimal BST (Best Case): 142
// Worst Case Cost (Skewed Tree): 184
