/**
 * @author : Rohit
 * @date   : 2025-02-21
 * @problem: Subarrays Divisible by K
 * @link   : https://leetcode.com/problems/subarray-sums-divisible-by-k/
 * @level  : Medium
 *
 * @description
 * Given an integer array `nums` and an integer `k`, return the number of subarrays
 * whose sum is divisible by `k`.
 *
 * @approach
 * **Prefix Sum with HashMap (Efficient Approach)**
 * 1. **Use a HashMap to Store Remainders**:
 *    - The key is the remainder of the prefix sum when divided by `k`.
 *    - The value is the frequency of that remainder appearing so far.
 * 2. **Iterate Through the Array**:
 *    - Maintain a running sum.
 *    - Compute `sum % k` (handling negative remainders by adding `k` to keep it non-negative).
 *    - If the remainder has been seen before, it means there exists a subarray whose sum is divisible by `k`.
 *    - Increase the count based on how many times this remainder has appeared.
 * 3. **Update the HashMap**:
 *    - Store the occurrence of the remainder.
 *
 * @complexity
 * **Time Complexity**: O(n) → Single pass through the array.
 * **Space Complexity**: O(k) → Storing at most `k` remainder values in a hashmap.
 *
 * @example
 * **Input**: nums = [4,5,0,-2,-3,1], k = 5
 * **Output**: 7
 * **Explanation**: The 7 valid subarrays are:
 *  - [4, 5, 0, -2, -3, 1]
 *  - [5, 0, -2, -3, 1]
 *  - [0, -2, -3, 1]
 *  - [-2, -3, 1]
 *  - [5]
 *  - [0, -2, -3]
 *  - [-3, 1]
 */

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();

        unordered_map<int, int> mpp;
        int sum = 0;
        mpp[0] = 1;
        int result = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            int rem = sum % k;

            if (rem < 0)
            {
                rem += k;
            }
            if (mpp.find(rem) != mpp.end())
            {
                result += mpp[rem];
            }
            mpp[rem]++;
        }
        return result;
    }
};