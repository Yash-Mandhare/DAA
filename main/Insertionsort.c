// Write a program to sort a list of n numbers in ascending order using Insertion sort and
// determine the time required to sort the elements.


#include <stdio.h>
#include <time.h>

int main() {
    int n, i, j, key, arr[100];
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    start = clock();  // Start time

    // Insertion Sort
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    end = clock();  // End time

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted array in ascending order:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nTime taken to sort: %f seconds\n", time_taken);

    return 0;
}

// Enter number of elements: 5
// Enter 5 elements:
// 9 3 5 1 7

// Sorted array in ascending order:
// 1 3 5 7 9
// Time taken to sort: 0.000001 seconds
