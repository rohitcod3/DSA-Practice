/**
 * @author : Rohit
 * @date   : 2024-12-15
 * @problem: Find Peak Element
 * @link   : https://leetcode.com/problems/find-peak-element/
 * @level  : Medium
 *
 * @description
 * This function finds a peak element in the array `nums` and returns its index.
 * A peak element is defined as an element that is strictly greater than its neighbors.
 *
 * - If the element is at the beginning, it is a peak if it is greater than its right neighbor.
 * - If the element is at the end, it is a peak if it is greater than its left neighbor.
 * - The function returns the first peak element found.
 *
 * @approach
 * 1. **Linear Search**:
 *    - Traverse the array from left to right.
 *    - For each element, check the following conditions:
 *      - If it is at the beginning (`i == 0`), ensure it is greater than its right neighbor (`nums[i] > nums[i + 1]`).
 *      - If it is at the end (`i == n - 1`), ensure it is greater than its left neighbor (`nums[i] > nums[i - 1]`).
 *      - Otherwise, check if it is strictly greater than both its left and right neighbors.
 *    - If any of these conditions are met, return the index of the current element.
 *
 * @complexity
 * Time Complexity: O(n), where `n` is the size of the array.
 * - Each element is processed once in the linear traversal.
 * Space Complexity: O(1), as no additional data structures are used.
 *
 * @example
 * Input: nums = [1, 2, 3, 1]
 * Output: 2
 * Explanation:
 * - The peak element is `3` at index `2`.
 *
 * Input: nums = [1, 2, 1, 3, 5, 6, 4]
 * Output: 5
 * Explanation:
 * - The peak element is `6` at index `5`.
 *
 */

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {

            if ((i == 0 || nums[i - 1] < nums[i]) && (i == n - 1 || nums[i] > nums[i + 1]))
            {
                return i;
            }
        }

        return -1;
    }
};
