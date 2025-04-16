// Write a program to implement Knapsack problems using Greedy method

#include <stdio.h>

int main() {
    int n;
    float w[50], p[50], r[50], cap, val = 0, t;

    printf("Enter number of items: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Weight & Profit of item %d: ", i + 1);
        scanf("%f%f", &w[i], &p[i]);
        r[i] = p[i] / w[i];
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &cap);

    // Sort by ratio
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (r[i] < r[j]) {
                t = r[i]; r[i] = r[j]; r[j] = t;
                t = w[i]; w[i] = w[j]; w[j] = t;
                t = p[i]; p[i] = p[j]; p[j] = t;
            }

    for (int i = 0; i < n && cap > 0; i++) {
        if (w[i] <= cap) {
            val += p[i];
            cap -= w[i];
        } else {
            val += r[i] * cap;
            break;
        }
    }

    printf("Max value: %.2f\n", val);
    return 0;
}


// Enter the number of items: 3 
// Enter Weight and Profit for item[0]:
// 10 60
// Enter Weight and Profit for item[1]:
// 20 100
// Enter Weight and Profit for item[2]:
// 30 120
// Enter the capacity of knapsack:
// 50

// Knapsack problem using Greedy Algorithm:

// The maximum value is: 240.00