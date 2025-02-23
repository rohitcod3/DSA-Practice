/**
 * @author : Rohit
 * @date   : 2025-02-21
 * @problem: Check if Subarray Sum is a Multiple of K
 * @link   : https://leetcode.com/problems/continuous-subarray-sum/
 * @level  : Medium
 *
 * @description
 * Given an integer array `nums` and an integer `k`, return `true` if there exists a
 * subarray of length **at least two** whose sum is a multiple of `k`. Otherwise, return `false`.
 *
 * @approach
 * **Prefix Sum with HashMap**
 * 1. **Use a HashMap to Store Remainders**:
 *    - The key is `sum % k`, which represents the remainder when the cumulative sum is divided by `k`.
 *    - The value is the earliest index where this remainder was found.
 * 2. **Iterate Through the Array**:
 *    - Maintain a running sum.
 *    - Compute `sum % k` (handling negative remainders by adding `k` to make it non-negative).
 *    - If the remainder has been seen before, it means there is a subarray with a sum that is a multiple of `k`.
 *    - The subarray length must be at least **2** (`i - mpp[remainder] >= 2`).
 *    - If a new remainder is encountered, store its index in the map.
 *
 * @complexity
 * **Time Complexity**: O(n) → Single pass through the array.
 * **Space Complexity**: O(k) → Storing at most `k` remainder values in a hashmap.
 *
 * @example
 * **Input**: nums = [23, 2, 4, 6, 7], k = 6
 * **Output**: true
 * **Explanation**: The subarray `[2, 4]` has sum `6`, which is a multiple of `6`.
 *
 * **Input**: nums = [23, 2, 6, 4, 7], k = 13
 * **Output**: false
 * **Explanation**: No subarray with a sum that is a multiple of `13`.
 */

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        int maxSum = sum;

        for (int i = k; i < n; i++)
        {
            sum = sum - nums[i - k] + nums[i];
            maxSum = max(maxSum, sum);
        }
        return static_cast<double>(maxSum) / k;
    }
};