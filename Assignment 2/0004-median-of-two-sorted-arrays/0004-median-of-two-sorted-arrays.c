#include <stdio.h>
#include <limits.h>
#include <math.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Ensure nums1 is the smaller array to minimize binary search range
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int m = nums1Size;
    int n = nums2Size;
    int low = 0, high = m;

    while (low <= high) {
        // Partition nums1 at i
        int i = (low + high) / 2;
        // Partition nums2 at j such that left parts have equal (or +1) elements
        int j = (m + n + 1) / 2 - i;

        // Handle edge cases where partition is at the start or end
        int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int minRight1 = (i == m) ? INT_MAX : nums1[i];

        int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int minRight2 = (j == n) ? INT_MAX : nums2[j];

        // Check if we have found the correct partition
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            // If total length is even
            if ((m + n) % 2 == 0) {
                return (fmax(maxLeft1, maxLeft2) + fmin(minRight1, minRight2)) / 2.0;
            } 
            // If total length is odd
            else {
                return fmax(maxLeft1, maxLeft2);
            }
        } 
        // If maxLeft1 is too big, move partition to the left in nums1
        else if (maxLeft1 > minRight2) {
            high = i - 1;
        } 
        // If maxLeft2 is too big, move partition to the right in nums1
        else {
            low = i + 1;
        }
    }

    // Should never reach here given valid inputs
    return 0.0;
}