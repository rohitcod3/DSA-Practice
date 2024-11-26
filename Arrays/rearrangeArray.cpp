/**
 * @author : Rohit
 * @date   : 2024-11-21
 * @problem: Rearrange Array Elements by Sign
 * @link   : https://leetcode.com/problems/rearrange-array-elements-by-sign/
 * @level  : Medium
 *
 * @description
 * This function rearranges an array such that positive and negative integers alternate, preserving their relative order.
 * The input array is guaranteed to have an equal number of positive and negative integers.
 * The rearranged array is returned with positive integers at even indices and negative integers at odd indices.
 *
 * @approach
 * 1. Create an auxiliary array `ans` to store the rearranged elements.
 * 2. Maintain two pointers:
 *    - `posIndex` (starting at 0) for the next positive integer's position.
 *    - `negIndex` (starting at 1) for the next negative integer's position.
 * 3. Traverse the input array:
 *    - If the current element is positive, place it at `posIndex` and increment `posIndex` by 2.
 *    - If the current element is negative, place it at `negIndex` and increment `negIndex` by 2.
 * 4. Return the rearranged array.
 *
 * @complexity
 * Time Complexity: O(n) - Single traversal of the input array.
 * Space Complexity: O(n) - Auxiliary array for storing the rearranged result.
 *
 * @example
 * Input: nums = [3, -1, 2, -2, 5, -4]
 * Output: [3, -1, 2, -2, 5, -4]
 * Explanation: Positive integers are at even indices, and negative integers are at odd indices.
 */

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        int posIndex = 0, negIndex = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
            else
            {
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
        }
        return ans;
    }
};