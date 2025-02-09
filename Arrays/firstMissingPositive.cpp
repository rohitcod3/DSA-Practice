/**
 * @author : Rohit
 * @date   : 2025-01-29  // (Ensure to update dynamically)
 * @problem: First Missing Positive Integer
 * @link   : https://leetcode.com/problems/first-missing-positive/
 * @level  : Hard
 *
 * @description
 * Given an unsorted integer array `nums`, the function finds the **smallest missing positive integer**.
 * It must be solved **in O(n) time** and **constant extra space O(1)**.
 *
 * @approach
 * 1. **Preprocessing Step:**
 *    - Check if `1` is present in the array.
 *    - Replace **negative numbers, zeros, and numbers greater than `n`** with `1` (since they are not relevant).
 *
 * 2. **Marking Step:**
 *    - Iterate through the array and mark indices **corresponding to existing numbers** as **negative**.
 *    - Example: If `nums[i] = 3`, mark `nums[2]` (index `3-1`) as **negative**.
 *
 * 3. **Finding the Missing Positive:**
 *    - Iterate again to find the **first positive number**. The missing positive integer is `i+1`.
 *    - If all indices are marked, return `n+1` (since all numbers `1` to `n` exist).
 *
 * @complexity
 * - **Time Complexity:** O(n) - All operations are linear.
 * - **Space Complexity:** O(1) - No extra space is used.
 *
 * @example
 * **Input:**
 * ```
 * nums = [3, 4, -1, 1]
 * ```
 * **Output:**
 * ```
 * 2
 * ```
 * **Explanation:**
 * - After replacing invalid numbers: `[3, 4, 1, 1]`
 * - Marking indices: `[-3, 4, -1, 1]`
 * - First positive missing number is `2`.
 *
 * @edge-cases
 * - **Array with all positive numbers:** `[1, 2, 3] → Output: 4`
 * - **Array with negative numbers:** `[-1, -2, -3] → Output: 1`
 * - **Unsorted arrays with gaps:** `[7, 8, 9, 11, 12] → Output: 1`
 */

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();

        bool contains1 = false;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                contains1 = true;
            }
            if (nums[i] <= 0 || nums[i] > n)
            {
                nums[i] = 1;
            }
        }

        if (contains1 == false)
        {
            return 1;
        }

        for (int i = 0; i < n; i++)
        {
            int num = abs(nums[i]);
            int idx = num - 1;

            if (nums[idx] < 0)
                continue;
            nums[idx] *= -1;
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                return i + 1;
            }
        }

        return n + 1;
    }
};