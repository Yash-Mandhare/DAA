// Write a program to sort n randomly generated elements using Heapsort method.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int a[], int n, int i) {
    int largest = i, l = 2*i+1, r = 2*i+2, temp;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        temp = a[i]; a[i] = a[largest]; a[largest] = temp;
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    for (int i = n/2-1; i >= 0; i--) heapify(a, n, i);
    for (int i = n-1; i >= 0; i--) {
        int t = a[0]; a[0] = a[i]; a[i] = t;
        heapify(a, i, 0);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    srand(time(0));
    printf("Random elements:\n");
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }

    heapSort(a, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);

    return 0;
}
