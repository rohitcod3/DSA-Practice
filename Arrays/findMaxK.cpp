/**
 * @author : Rohit
 * @date   : 2025-02-05
 * @problem: Largest Positive Integer That Exists With Its Negative
 * @link   : https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/
 * @level  : Easy
 *
 * @description
 * Given an array `nums` of integers, this function finds the largest positive integer `k`
 * such that both `k` and `-k` exist in the array. If no such integer exists, return `-1`.
 *
 * @approach
 * 1. **Brute Force Approach**:
 *    - Iterate through each element `nums[i]` and check if `-nums[i]` exists in `nums`.
 *    - Maintain the maximum absolute value found.
 * 2. **Optimization**:
 *    - This approach runs in **O(n²)** due to the nested loop.
 *    - A better approach would be using an unordered set to check existence in **O(n)**.
 *
 * @complexity
 * - **Time Complexity:** **O(n²)**, since we use a nested loop to check for `-nums[i]`.
 * - **Space Complexity:** **O(1)**, as no extra data structures are used.
 *
 * @example
 * **Input:** nums = [-1,2,-3,3]
 * **Output:** 3
 * **Explanation:** Both `3` and `-3` exist, and `3` is the largest such number.
 */

class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {

        int n = nums.size();
        int result = -1;
        for (int i = 0; i < n; i++)
        {
            int first = nums[i];

            for (int j = 0; j < n; j++)
            {
                int number = -(nums[j]);
                if (nums[i] == number)
                {
                    result = max(abs(nums[i]), result);
                }
            }
        }

        return result;
    }
};