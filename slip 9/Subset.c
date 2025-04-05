// Write a program to implement Sum of Subset by Backtracking

#include <stdio.h>

int set[20], solution[20], n, target;

void subset(int index, int currSum, int currIndex) {
    if (currSum == target) {
        printf("Subset: ");
        for (int i = 0; i < currIndex; i++)
            printf("%d ", solution[i]);
        printf("\n");
        return;
    }

    if (index >= n || currSum > target)
        return;

    // Include current element
    solution[currIndex] = set[index];
    subset(index + 1, currSum + set[index], currIndex + 1);

    // Exclude current element
    subset(index + 1, currSum, currIndex);
}

int main() {
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("\nSubsets with sum %d are:\n", target);
    subset(0, 0, 0);

    return 0;
}


// Enter number of elements: 4
// Enter elements:
// 2 4 6 10
// Enter target sum: 16

// Subsets with sum 16 are:
// Subset: 2 4 10
// Subset: 6 10
