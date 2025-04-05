// Write a program to sort a list of n numbers in ascending order using selection sort and
// determine the time required to sort the elements .

#include <stdio.h>
#include <time.h>

int main() {
    int n, i, j, min, temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    clock_t start = clock();

    // Selection sort
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}



// Enter number of elements: 4
// Enter the elements:
// 8 6 3 10
// Sorted array:
// 3 6 8 10 
// Time taken: 1200 nanoseconds