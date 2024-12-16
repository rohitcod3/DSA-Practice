/**
 * @author : Rohit
 * @date   : 2024-12-16
 * @problem: Merge Sorted Arrays Without Extra Space
 * @link   : https://leetcode.com/problems/merge-sorted-array/
 * @level  : Hard
 *
 * @description
 * This function merges two sorted arrays `nums1` and `nums2` into a single sorted array without using extra space.
 * - The result is stored in `nums1`, which has enough space to accommodate both arrays.
 *
 * @approach
 * 1. **Gap Algorithm**:
 *    - Use the "gap method" to compare and swap elements across the two arrays:
 *      - Calculate an initial gap as `(m + n) / 2`.
 *      - Compare and swap elements separated by the gap.
 *      - Reduce the gap iteratively until it becomes 1.
 * 2. **Merge Logic**:
 *    - Compare elements in `nums1` and `nums2` or within the same array.
 *    - Swap them if they are out of order.
 *    - Once the process is complete, the smaller elements are in `nums1` and larger elements in `nums2`.
 * 3. **Final Copy**:
 *    - Copy the elements from `nums2` to the remaining space in `nums1`.
 *
 * @complexity
 * Time Complexity: O((m + n) * log(m + n)), where `m` and `n` are the sizes of `nums1` and `nums2`, respectively.
 * Space Complexity: O(1), as no extra space is used beyond the input arrays.
 *
 * @example
 * Input: nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3
 * Output: nums1 = [1, 2, 2, 3, 5, 6]
 * Explanation:
 * - Merged the two arrays in place without using extra space.
 */

class Solution
{
private:
    void swapIfGreater(vector<int> &nums1, vector<int> &nums2, int ind1, int ind2)
    {
        if (nums1[ind1] > nums2[ind2])
        {
            swap(nums1[ind1], nums2[ind2]);
        }
    }

public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int len = m + n;
        int gap = (len / 2) + (len % 2);

        while (gap > 0)
        {
            int left = 0;
            int right = gap;

            while (right < len)
            {
                if (left < m && right < m)
                {

                    swapIfGreater(nums1, nums1, left, right);
                }
                else if (left < m && right >= m)
                {

                    swapIfGreater(nums1, nums2, left, right - m);
                }
                else
                {

                    swapIfGreater(nums2, nums2, left - m, right - m);
                }
                left++;
                right++;
            }

            if (gap == 1)
                break;
            gap = (gap / 2) + (gap % 2);
        }

        for (int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i];
        }
    }
};
