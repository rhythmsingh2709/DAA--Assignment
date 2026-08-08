/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// Helper function to merge two sorted subarrays
void merge(int* nums, int left, int mid, int right, int* temp) {
    int i = left;       // Starting index for left subarray
    int j = mid + 1;    // Starting index for right subarray
    int k = left;       // Starting index for temp array

    // Compare elements from both subarrays and merge in sorted order
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    // Copy remaining elements from left subarray (if any)
    while (i <= mid) {
        temp[k++] = nums[i++];
    }

    // Copy remaining elements from right subarray (if any)
    while (j <= right) {
        temp[k++] = nums[j++];
    }

    // Copy sorted elements back to original array
    for (i = left; i <= right; i++) {
        nums[i] = temp[i];
    }
}

// Recursive Merge Sort function
void mergeSort(int* nums, int left, int right, int* temp) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Prevents overflow

        // Recursively sort left and right halves
        mergeSort(nums, left, mid, temp);
        mergeSort(nums, mid + 1, right, temp);

        // Merge the sorted halves
        merge(nums, left, mid, right, temp);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    
    // Allocate temporary array for merging (O(n) space)
    int* temp = (int*)malloc(numsSize * sizeof(int));
    if (temp == NULL) {
        return NULL; // Handle memory allocation failure
    }

    // Perform Merge Sort
    mergeSort(nums, 0, numsSize - 1, temp);

    // Free temporary array
    free(temp);

    return nums;
}