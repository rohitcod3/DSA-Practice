/**
 * @author : Rohit
 * @date   : 2024-12-28
 * @problem: Find Minimum in Rotated Sorted Array
 * @link   : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 * @level  : Medium
 *
 * @description
 * This function finds the minimum element in a rotated sorted array `nums`.
 * The array was initially sorted in ascending order and then rotated at some pivot point.
 * The function uses a modified binary search to efficiently locate the minimum element.
 *
 * @approach
 * 1. **Binary Search**:
 *    - Use two pointers, `low` and `high`, to traverse the array.
 *    - Calculate the middle index `mid` as `(low + high) / 2`.
 * 2. **Check Sorted Subarray**:
 *    - If the left half (`nums[low]` to `nums[mid]`) is sorted:
 *      - The minimum element in this range is `nums[low]`.
 *      - Update `ans` to the smaller of `ans` and `nums[low]`.
 *      - Move the `low` pointer to `mid + 1` to search the right half.
 *    - If the left half is not sorted, the right half must be sorted:
 *      - The minimum element in this range is `nums[mid]`.
 *      - Update `ans` to the smaller of `ans` and `nums[mid]`.
 *      - Move the `high` pointer to `mid - 1` to search the left half.
 * 3. **Return the Minimum**:
 *    - The `ans` variable contains the smallest element in the array.
 *
 * @complexity
 * Time Complexity: O(log n), where `n` is the size of the array.
 * - The search space is halved in each iteration.
 * Space Complexity: O(1), as no additional data structures are used.
 *
 * @example
 * Input: nums = [3, 4, 5, 1, 2]
 * Output: 1
 * Explanation:
 * - The array is rotated, and the minimum element is `1`.
 *
 * Input: nums = [4, 5, 6, 7, 0, 1, 2]
 * Output: 0
 * Explanation:
 * - The array is rotated, and the minimum element is `0`.
 */

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int ans = INT_MAX;
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[low] <= nums[mid])
            {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
                ans = min(ans, nums[mid]);
            }
        }
        return ans;
    }
};