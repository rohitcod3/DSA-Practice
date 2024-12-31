/**
 * @author : Rohit
 * @date   : 2024-12-31
 * @problem: Find Peak Element
 * @link   : https://leetcode.com/problems/find-peak-element/
 * @level  : Medium
 *
 * @description
 * This function finds a peak element in the array `nums` and returns its index.
 * A peak element is defined as an element that is strictly greater than its neighbors.
 *
 * - If the array contains only one element, it is a peak.
 * - If the peak exists at the beginning or end of the array, handle these edge cases directly.
 * - Otherwise, use binary search to efficiently locate a peak element.
 *
 * @approach
 * 1. **Edge Case Handling**:
 *    - If the array contains one element, return `0` as its index.
 *    - If the first element is greater than the second, return `0`.
 *    - If the last element is greater than the second-last, return `n - 1`.
 * 2. **Binary Search**:
 *    - Use two pointers, `low` and `high`, initialized to `1` and `n - 2` respectively (excluding edges).
 *    - Calculate the middle index `mid` as `(low + high) / 2`.
 *    - Check if `nums[mid]` is a peak:
 *      - `nums[mid] > nums[mid - 1]` and `nums[mid] > nums[mid + 1]`.
 *    - Adjust search space:
 *      - If `nums[mid] > nums[mid - 1]`, move `low = mid + 1`.
 *      - Otherwise, move `high = mid - 1`.
 * 3. **Return the Peak**:
 *    - The function returns the index of the peak element.
 *
 * @complexity
 * Time Complexity: O(log n), where `n` is the size of the array.
 * - The search space is halved in each iteration.
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
 * @note
 * There can be multiple peaks in the array; this function returns the index of any one peak.
 */

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int low = 1, high = n - 2;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            else if (nums[mid] > nums[mid - 1])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};
