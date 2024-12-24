/**
 * @author : Rohit
 * @date   : 2024-12-24
 * @problem: Search Insert Position
 * @link   : https://leetcode.com/problems/search-insert-position/
 * @level  : Easy
 *
 * @description
 * This function finds the index at which a target value should be inserted into a sorted array `nums`
 * to maintain its sorted order. If the target already exists in the array, it returns the index of the target.
 *
 * @approach
 * 1. **Binary Search**:
 *    - Use two pointers, `low` and `high`, to traverse the array.
 *    - Calculate the middle index `mid` as `(low + high) / 2`.
 *    - Compare `nums[mid]` with the `target`:
 *      - If `nums[mid] >= target`, update `ans = mid` and move the `high` pointer to `mid - 1`.
 *      - If `nums[mid] < target`, move the `low` pointer to `mid + 1`.
 *    - Continue until `low > high`.
 * 2. **Return the Result**:
 *    - The `ans` variable contains the index where the target should be inserted.
 *
 * @complexity
 * Time Complexity: O(log n), where `n` is the size of the array.
 * - The search space is halved in each iteration.
 * Space Complexity: O(1), as no additional space is used.
 *
 * @example
 * Input: nums = [1, 3, 5, 6], target = 5
 * Output: 2
 * Explanation:
 * - The target value `5` is found at index `2`.
 *
 * Input: nums = [1, 3, 5, 6], target = 2
 * Output: 1
 * Explanation:
 * - The target value `2` should be inserted at index `1` to maintain sorted order.
 *
 * Input: nums = [1, 3, 5, 6], target = 7
 * Output: 4
 * Explanation:
 * - The target value `7` should be inserted at index `4` (end of the array).
 */

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();

        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] >= target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};