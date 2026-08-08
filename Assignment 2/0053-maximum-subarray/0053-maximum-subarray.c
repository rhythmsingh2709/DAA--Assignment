int maxSubArray(int* nums, int numsSize) {
    // Initialize max_sum to the smallest possible integer to handle arrays with all negative numbers
    // or initialize with the first element.
    int max_sum = nums[0];
    int current_sum = 0;

    for (int i = 0; i < numsSize; i++) {
        // Add current element to the running sum
        current_sum += nums[i];

        // Update max_sum if current_sum is greater
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }

        // If current_sum becomes negative, reset it to 0.
        // A negative sum will only reduce the sum of future subarrays.
        if (current_sum < 0) {
            current_sum = 0;
        }
    }

    return max_sum;
}