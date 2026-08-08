int findPeakElement(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    // Binary search loop
    while (left < right) {
        int mid = left + (right - left) / 2;

        // Compare mid with its right neighbor
        if (nums[mid] < nums[mid + 1]) {
            // We are in an ascending slope.
            // The peak must be to the right.
            left = mid + 1;
        } else {
            // We are in a descending slope or at a peak.
            // The peak is at mid or to the left.
            right = mid;
        }
    }

    // When left == right, we found a peak
    return left;
}