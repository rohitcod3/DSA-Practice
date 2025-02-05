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
 * 1. **Sorting + Two Pointers Approach**:
 *    - First, sort the array.
 *    - Use two pointers: one starting from the left (`i = 0`) and the other from the right (`j = n-1`).
 *    - If `nums[i] == -nums[j]`, return the absolute value of `nums[i]`.
 *    - If `-nums[i] < nums[j]`, decrement `j` (move towards smaller numbers).
 *    - If `-nums[i] > nums[j]`, increment `i` (move towards larger numbers).
 * 2. **Optimized from O(n²) to O(n log n)**
 *    - Sorting takes **O(n log n)**.
 *    - Two-pointer search takes **O(n)**.
 *
 * @complexity
 * - **Time Complexity:** **O(n log n)** (sorting) + **O(n)** (two-pointer search) = **O(n log n)**.
 * - **Space Complexity:** **O(1)**, as sorting is done in place and no extra data structures are used.
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
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = n - 1;

        while (i < j)
        {
            if (nums[i] == -(nums[j]))
                return abs(nums[i]);

            int counterPart = -(nums[i]);

            if (counterPart < nums[j])
                j--;

            if (counterPart > nums[j])
                i++;
        }
        return -1;
    }
};