// Write a program to implement Knapsack problems using Greedy method

#include<stdio.h>

int main()
{
    float weight[50], profit[50], ratio[50], Totalvalue = 0.0, temp;
    float capacity, amount;
    int n, i, j;

    printf("Enter the number of items: ");
    scanf("%d", &n);   

    for (i = 0; i < n; i++)
    {
        printf("Enter Weight and Profit for item[%d]:\n", i);
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("Enter the capacity of knapsack:\n");
    scanf("%f", &capacity);

    // Calculate profit/weight ratio
    for (i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    // Sort items by ratio in descending order
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                // Swap ratio
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // Swap weight
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                // Swap profit
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    printf("\nKnapsack problem using Greedy Algorithm:\n");

    for (i = 0; i < n; i++)
    {
        if (weight[i] <= capacity)
        {
            Totalvalue += profit[i];
            capacity -= weight[i];
        }
        else
        {
            Totalvalue += ratio[i] * capacity; // Take the fractional part
            break;
        }
    }

    printf("\nThe maximum value is: %.2f\n", Totalvalue);
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