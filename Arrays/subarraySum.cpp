/**
 * @author : Rohit
 * @problem: Subarray Sum Equals K
 * @link   : https://leetcode.com/problems/subarray-sum-equals-k/
 * @level  : Medium
 *
 * @description
 * This function counts the number of contiguous subarrays in the given array `nums`
 * whose sum equals `k`. It uses a brute-force approach to iterate over all possible
 * subarrays and checks their cumulative sum.
 *
 * @approach
 * 1. Use two nested loops:
 *    - The outer loop starts a subarray from each index `i`.
 *    - The inner loop iterates through all elements from index `i` to the end.
 * 2. For each subarray, calculate the cumulative sum.
 * 3. Increment the counter if the sum equals `k`.
 *
 * @complexity
 * Time Complexity: O(n^2) - Two nested loops for subarray sum calculation.
 * Space Complexity: O(1) - No additional space used.
 */

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int counter = 0;

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];

                if (sum == k)
                {
                    counter++;
                }
            }
        }
        return counter;
    }
};