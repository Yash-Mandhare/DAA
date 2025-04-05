// Write a program to implement Huffman Code using greedy methods and also calculate the
// best case and worst-case complexity.

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    char data;
    int freq;
    struct Node *left, *right;
};

// Min Heap structure
struct MinHeap {
    int size;
    struct Node* array[100];
};

// Create new node
struct Node* newNode(char data, int freq) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

// Swap nodes
void swap(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

// Heapify
void minHeapify(struct MinHeap* heap, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < heap->size && heap->array[l]->freq < heap->array[smallest]->freq)
        smallest = l;
    if (r < heap->size && heap->array[r]->freq < heap->array[smallest]->freq)
        smallest = r;
    if (smallest != i) {
        swap(&heap->array[i], &heap->array[smallest]);
        minHeapify(heap, smallest);
    }
}

// Build min heap
void buildMinHeap(struct MinHeap* heap) {
    for (int i = (heap->size - 2) / 2; i >= 0; --i)
        minHeapify(heap, i);
}

// Extract minimum node
struct Node* extractMin(struct MinHeap* heap) {
    struct Node* temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    minHeapify(heap, 0);
    return temp;
}

// Insert node into heap
void insertMinHeap(struct MinHeap* heap, struct Node* node) {
    ++heap->size;
    int i = heap->size - 1;
    while (i && node->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

// Print Huffman Codes
void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Build Huffman Tree
void HuffmanCodes(char data[], int freq[], int size) {
    struct Node *left, *right, *top;
    struct MinHeap heap;
    heap.size = size;

    for (int i = 0; i < size; ++i)
        heap.array[i] = newNode(data[i], freq[i]);

    buildMinHeap(&heap);

    while (heap.size > 1) {
        left = extractMin(&heap);
        right = extractMin(&heap);

        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(&heap, top);
    }

    int arr[100], topIndex = 0;
    printf("Huffman Codes:\n");
    printCodes(heap.array[0], arr, topIndex);
}

// Main function
int main() {
    char data[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(data) / sizeof(data[0]);
    HuffmanCodes(data, freq, size);
    return 0;
}


// Huffman Codes:
// F: 0
// C: 100
// D: 101
// A: 1100
// B: 1101
// E: 111