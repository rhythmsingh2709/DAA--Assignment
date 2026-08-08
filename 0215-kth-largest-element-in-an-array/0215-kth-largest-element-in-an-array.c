#include <stdlib.h>

typedef struct {
    int* data;
    int size;
} MinHeap;

void swap(int* a, int* b) {
    int t = *a; *a = *b; *b = t;
}

void heapifyDown(int* arr, int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapifyDown(arr, n, smallest);
    }
}

void heapifyUp(int* arr, int i) {
    while (i > 0 && arr[i] < arr[(i - 1) / 2]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    int* heap = (int*)malloc(k * sizeof(int));
    int size = 0;

    for (int i = 0; i < numsSize; i++) {
        if (size < k) {
            heap[size++] = nums[i];
            heapifyUp(heap, size - 1);
        } else if (nums[i] > heap[0]) {
            heap[0] = nums[i];
            heapifyDown(heap, k, 0);
        }
    }

    int result = heap[0];
    free(heap);
    return result;
}