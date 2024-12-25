/**
 * @author : Rohit
 * @date   : 2024-12-25
 * @problem: Find First and Last Position of Element in Sorted Array
 * @link   : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * @level  : Medium
 *
 * @description
 * This function finds the starting and ending positions of a target value in a sorted array `nums`.
 * If the target is not found, it returns `[-1, -1]`.
 *
 * The solution leverages binary search to efficiently determine the bounds:
 * - `lowerBound`: Finds the first occurrence of the target or the smallest index where `nums[index] >= target`.
 * - `upperBound`: Finds the smallest index where `nums[index] > target`.
 *
 * If the target exists, the range is `[lowerBound, upperBound - 1]`.
 *
 * @approach
 * 1. **Lower Bound**:
 *    - Use binary search to find the first occurrence of the target or the smallest index where `nums[index] >= target`.
 *    - Update `ans` to `mid` whenever `nums[mid] >= target` and move the `high` pointer to `mid - 1`.
 * 2. **Upper Bound**:
 *    - Use binary search to find the smallest index where `nums[index] > target`.
 *    - Update `ans` to `mid` whenever `nums[mid] > target` and move the `high` pointer to `mid - 1`.
 * 3. **Check Validity**:
 *    - If `lowerBound` points to an index out of bounds or the value at `nums[lowerBound]` is not equal to the target, return `[-1, -1]`.
 * 4. **Return Range**:
 *    - Return `[lowerBound, upperBound - 1]` as the range where the target exists.
 *
 * @complexity
 * Time Complexity: O(log n), where `n` is the size of the array.
 * - Each binary search operation takes ( O(\log n) ).
 * - Two binary search calls are made.
 * Space Complexity: O(1), as no additional data structures are used.
 *
 * @example
 * Input: nums = [5, 7, 7, 8, 8, 10], target = 8
 * Output: [3, 4]
 * Explanation:
 * - The target `8` is found at indices `3` and `4`.
 *
 * Input: nums = [5, 7, 7, 8, 8, 10], target = 6
 * Output: [-1, -1]
 * Explanation:
 * - The target `6` does not exist in the array.
 */

class Solution
{
public:
    int lowerBound(vector<int> &nums, int target)
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

    int upperBound(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = n;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] > target)
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

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int lb = lowerBound(nums, target);
        if (lb == n || nums[lb] != target)
            return {-1, -1};
        return {lb, upperBound(nums, target) - 1};
    }
};