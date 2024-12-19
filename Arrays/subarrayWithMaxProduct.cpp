/**
 * @author : Rohit
 * @date   : 2024-12-19
 * @problem: Maximum Product Subarray
 * @link   : https://leetcode.com/problems/maximum-product-subarray/
 * @level  : Medium
 *
 * @description
 * This function calculates the maximum product of a contiguous subarray within the given array `nums`.
 * It uses a prefix and suffix approach to efficiently handle cases with negative numbers and zeros.
 *
 * @approach
 * 1. **Prefix and Suffix Products**:
 *    - Use two pointers: one for calculating the prefix product (from left to right) and another for the suffix product (from right to left).
 *    - Reset the product to 1 whenever it becomes 0, as 0 breaks the product continuity.
 * 2. **Iterate Through the Array**:
 *    - Compute the prefix product and suffix product for every element.
 *    - Track the maximum product encountered.
 * 3. **Edge Cases**:
 *    - Handles arrays with zeros, positive and negative numbers.
 *    - If the array has all zeros, the result will be 0.
 *
 * @complexity
 * Time Complexity: O(n), where `n` is the size of the array.
 * - Single traversal of the array for prefix and suffix calculations.
 * Space Complexity: O(1), as no extra space is used beyond variables.
 *
 * @example
 * Input: nums = [2, 3, -2, 4]
 * Output: 6
 * Explanation:
 * - The subarray [2, 3] has the maximum product of 6.
 *
 * Input: nums = [-2, 0, -1]
 * Output: 0
 * Explanation:
 * - The subarray [0] or any subarray containing 0 results in the maximum product of 0.
 */

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int ans = INT_MIN;
        int prefix = 1, suffix = 1;
        for (int i = 0; i < n; i++)
        {
            if (prefix == 0)
                prefix = 1;
            if (suffix == 0)
                suffix = 1;

            prefix = prefix * nums[i];
            suffix = suffix * nums[n - i - 1];
            ans = max(ans, max(prefix, suffix));
        }
        return ans;
    }
};