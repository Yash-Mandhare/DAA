// Write a program to implement a Merge Sort algorithm to sort a given set of elements and
// determine the time required to sort the elements

#include <stdio.h>
#include <time.h>

void merge(int a[], int l, int m, int r) {
    int i=l, j=m+1, k=0, b[100];
    while(i <= m && j <= r)
        b[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
    while(i <= m) b[k++] = a[i++];
    while(j <= r) b[k++] = a[j++];
    for(i=l, k=0; i <= r; i++, k++) a[i] = b[k];
}

void mergeSort(int a[], int l, int r) {
    if(l < r) {
        int m = (l + r)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int a[100], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) scanf("%d", &a[i]);

    clock_t start = clock();
    mergeSort(a, 0, n-1);
    clock_t end = clock();

    printf("Sorted array:\n");
    for(i = 0; i < n; i++) printf("%d ", a[i]);

    printf("\nTime taken: %.6f sec\n", (double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}

// Enter number of elements: 5
// Enter elements:
// 23 45 12 9 34
// Sorted array:
// 9 12 23 34 45
// Time taken: 0.000000 sec