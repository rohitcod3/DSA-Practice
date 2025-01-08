/**
 * @author : Rohit
 * @date   : 2025-01-04
 * @problem: Median of Two Sorted Arrays
 * @link   : https://leetcode.com/problems/median-of-two-sorted-arrays/
 * @level  : Hard
 *
 * @description
 * This function finds the median of two sorted arrays `nums1` and `nums2`.
 *
 * The arrays are merged into a single sorted array `nums3`, and the median is calculated based on the combined length of the two arrays.
 *
 * @approach
 * 1. **Merge Two Arrays**:
 *    - Use two pointers `i` and `j` to iterate through `nums1` and `nums2` respectively.
 *    - Compare elements from both arrays and push the smaller one into the result array `nums3`.
 *    - Append the remaining elements from either array once one pointer reaches the end.
 * 2. **Calculate Median**:
 *    - If the combined length of the arrays (`n`) is odd, return the middle element: `nums3[n / 2]`.
 *    - If the combined length is even, return the average of the two middle elements:
 *      \( \text{median} = \frac{\text{nums3[n/2]} + \text{nums3[n/2 - 1]}}{2} \).
 *
 * @complexity
 * Time Complexity: O(n1 + n2), where `n1` is the size of `nums1` and `n2` is the size of `nums2`.
 * - Merging two arrays takes O(n1 + n2).
 * Space Complexity: O(n1 + n2), as an additional array `nums3` is created to store the merged result.
 *
 * @example
 * Input: nums1 = [1, 3], nums2 = [2]
 * Output: 2.0
 * Explanation:
 * - Merged array: [1, 2, 3]
 * - Median: 2
 *
 * Input: nums1 = [1, 2], nums2 = [3, 4]
 * Output: 2.5
 * Explanation:
 * - Merged array: [1, 2, 3, 4]
 * - Median: (2 + 3) / 2 = 2.5
 */

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> nums3;
        int i = 0, j = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        while (i < n1 && j < n2)
        {
            if (nums1[i] < nums2[j])
                nums3.push_back(nums1[i++]);
            else
                nums3.push_back(nums2[j++]);
        }
        while (i < n1)
            nums3.push_back(nums1[i++]);
        while (j < n2)
            nums3.push_back(nums2[j++]);
        int n = n1 + n2;
        if (n % 2 == 1)
        {
            return nums3[n / 2];
        }

        return (double)((double)(nums3[n / 2]) + (double)(nums3[n / 2 - 1])) / 2.0;
    }
};