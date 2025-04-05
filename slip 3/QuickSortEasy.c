// Write a program to sort a given set of elements using the Quick sort method and determine
// the time required to sort the elements

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int i = low, j = high, pivot = arr[low];
        while (i < j) {
            while (arr[i] <= pivot && i < high) i++;
            while (arr[j] > pivot) j--;
            if (i < j) {
                int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            }
        }
        arr[low] = arr[j]; arr[j] = pivot;
        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000;

    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Sorted %d elements in %.2f ms\n", n, time_taken);

    return 0;
}


// Enter number of elements: 5000
// Sorted 5000 elements in 1.00 ms
