/**
 * @author : Rohit
 * @date   : 2024-12-27
 * @problem: Search in Rotated Sorted Array II
 * @link   : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
 * @level  : Medium
 *
 * @description
 * This function determines whether a target value exists in a rotated sorted array `nums`
 * that may contain duplicate elements. If the target exists, it returns `true`; otherwise, it returns `false`.
 *
 * The function uses a modified binary search algorithm to account for duplicates in the array.
 *
 * @approach
 * 1. **Binary Search**:
 *    - Use two pointers, `low` and `high`, to traverse the array.
 *    - Calculate the middle index `mid` as `(low + high) / 2`.
 * 2. **Handle Duplicates**:
 *    - If `nums[low] == nums[mid] == nums[high]`, increment `low` and decrement `high` to skip duplicates.
 * 3. **Identify Sorted Half**:
 *    - Check if the left half (`nums[low]` to `nums[mid]`) is sorted:
 *      - If yes, check if the target lies in this range:
 *        - If yes, search the left half by updating `high = mid - 1`.
 *        - Otherwise, search the right half by updating `low = mid + 1`.
 *    - If the left half is not sorted, the right half must be sorted:
 *      - Check if the target lies in the right half:
 *        - If yes, search the right half by updating `low = mid + 1`.
 *        - Otherwise, search the left half by updating `high = mid - 1`.
 * 4. **Return Result**:
 *    - If the loop exits without finding the target, return `false`.
 *
 * @complexity
 * Time Complexity: O(n) in the worst case (due to duplicates); O(log n) in the average case.
 * Space Complexity: O(1), as no additional data structures are used.
 *
 * @example
 * Input: nums = [2, 5, 6, 0, 0, 1, 2], target = 0
 * Output: true
 * Explanation:
 * - The target value `0` exists in the array.
 *
 * Input: nums = [2, 5, 6, 0, 0, 1, 2], target = 3
 * Output: false
 * Explanation:
 * - The target value `3` does not exist in the array.
 */

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++, high--;
                continue;
            }

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
        return false;
    }
};