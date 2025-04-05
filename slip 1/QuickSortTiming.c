// Write a program to sort a given set of elements using the Quick sort method and determine
// the time required to sort the elements. Repeat the experiment for different values of n, the
// number of elements in the list to be sorted. The elements can be read from a file or can be
// generated using the random number generator. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int i = low, j = high;
        int pivot = arr[low];
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
    int sizes[] = {1000, 5000, 10000, 20000};
    int n;
    srand(time(0));

    for (int k = 0; k < 4; k++) {
        n = sizes[k];
        int arr[n];
        for (int i = 0; i < n; i++)
            arr[i] = rand() % 100000;

        clock_t start = clock();
        quickSort(arr, 0, n - 1);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("n = %d | Time taken: %.2f ms\n", n, time_taken);
    }

    return 0;
}


// n = 1000 | Time taken: 0.90 ms  
// n = 5000 | Time taken: 4.40 ms  
// n = 10000 | Time taken: 9.20 ms  
// n = 20000 | Time taken: 19.85 ms  
