/**
 * @author : Rohit
 * @date   : 2025-02-18
 * @problem: Increasing Triplet Subsequence
 * @link   : https://leetcode.com/problems/increasing-triplet-subsequence/
 * @level  : Medium
 *
 * @description
 * Given an integer array `nums`, this function determines whether there exists an increasing triplet
 * subsequence. In other words, it returns true if there exist indices `i`, `j`, and `k` such that
 * `i < j < k` and `nums[i] < nums[j] < nums[k]`; otherwise, it returns false.
 *
 * @approach
 * 1. **Two-Variable Tracking**:
 *    - Initialize two variables, `num1` and `num2`, with the maximum possible integer value (`INT_MAX`).
 * 2. **Iterate Through the Array**:
 *    - For each element in `nums`:
 *      - If the current element is less than or equal to `num1`, update `num1`.
 *      - Else if it is less than or equal to `num2`, update `num2`.
 *      - Otherwise, if the element is greater than both, an increasing triplet is found and return `true`.
 *
 * @complexity
 * - **Time Complexity:** O(n), where n is the number of elements in `nums`.
 * - **Space Complexity:** O(1), as only a constant amount of extra space is used.
 *
 * @example
 * Input: nums = [1,2,3,4,5]
 * Output: true
 * Explanation: The triplet (1,2,3) forms an increasing sequence.
 *
 * Input: nums = [5,4,3,2,1]
 * Output: false
 * Explanation: No increasing triplet subsequence exists.
 */
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();
        int num1 = INT_MAX;
        int num2 = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= num1)
            {
                num1 = nums[i];
            }
            else if (nums[i] <= num2)
            {
                num2 = nums[i];
            }
            else
            {
                return true; // Found a number greater than both num1 and num2
            }
        }

        return false;
    }
};
