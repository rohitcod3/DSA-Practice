/**
 * @author : Rohit
 * @date   : 2024-12-26
 * @problem: Search in Rotated Sorted Array
 * @link   : https://leetcode.com/problems/search-in-rotated-sorted-array/
 * @level  : Medium
 *
 * @description
 * This function searches for a target value in a rotated sorted array `nums` and returns its index.
 * If the target does not exist, it returns `-1`.
 *
 * A rotated sorted array is an array that was originally sorted in ascending order but then rotated
 * at some pivot. The function uses a modified binary search algorithm to find the target efficiently.
 *
 * @approach
 * 1. **Binary Search**:
 *    - Use two pointers, `low` and `high`, to traverse the array.
 *    - Calculate the middle index `mid` as `(low + high) / 2`.
 * 2. **Identify Sorted Half**:
 *    - Check if the left half (`nums[low]` to `nums[mid]`) is sorted:
 *      - If yes, check if the target lies in this range:
 *        - If yes, search the left half by updating `high = mid - 1`.
 *        - Otherwise, search the right half by updating `low = mid + 1`.
 *    - If the left half is not sorted, the right half must be sorted:
 *      - Check if the target lies in the right half:
 *        - If yes, search the right half by updating `low = mid + 1`.
 *        - Otherwise, search the left half by updating `high = mid - 1`.
 * 3. **Return Result**:
 *    - If the loop exits without finding the target, return `-1`.
 *
 * @complexity
 * Time Complexity: O(log n), where `n` is the size of the array.
 * - The search space is halved in each iteration.
 * Space Complexity: O(1), as no additional data structures are used.
 *
 * @example
 * Input: nums = [4, 5, 6, 7, 0, 1, 2], target = 0
 * Output: 4
 * Explanation:
 * - The target value `0` is found at index `4`.
 *
 * Input: nums = [4, 5, 6, 7, 0, 1, 2], target = 3
 * Output: -1
 * Explanation:
 * - The target value `3` is not found in the array.
 */

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (nums[mid] <= target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};