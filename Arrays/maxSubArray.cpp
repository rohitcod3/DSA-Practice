/**
 * @author : Rohit
 * @date   : 2024-11-21
 * @problem: Maximum Subarray
 * @link   : https://leetcode.com/problems/maximum-subarray/
 * @level  : Medium
 *
 * @description
 * This function calculates the maximum sum of a contiguous subarray using Kadane's Algorithm.
 *
 *
 * @approach
 * 1. Initialize `sum` to 0 and `maxi` to the smallest possible integer (`INT_MIN`).
 * 2. Traverse the array:
 *    - Add the current element to `sum`.
 *    - Update `maxi` with the maximum of `sum` and `maxi`.
 *    - If `sum` becomes negative, reset `sum` to 0 (start a new subarray).
 * 3. Return `maxi` as the largest subarray sum.
 *
 * @complexity
 * Time Complexity: O(n) - Single traversal of the array.
 * Space Complexity: O(1) - No additional space used.
 *
 */

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int maxi = INT_MIN;

        for (auto it : nums)
        {
            sum += it;
            maxi = max(sum, maxi);
            if (sum < 0)
                sum = 0;
        }
        return maxi;
    }
};