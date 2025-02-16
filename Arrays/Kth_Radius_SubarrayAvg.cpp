/**
 * @author : Rohit
 * @date   : 2025-02-16
 * @problem: K Radius Subarray Averages
 * @link   : https://leetcode.com/problems/k-radius-subarray-averages/
 * @level  : Medium
 *
 * @description
 * Given an integer array `nums` and an integer `k`, this function returns an array `result` of the same length
 * where `result[i]` is the average of the subarray of `nums` centered at `i` with radius `k`. If there are fewer
 * than `2*k+1` elements to form a full window around index `i`, `result[i]` is set to `-1`.
 *
 * @approach
 * 1. **Prefix Sum Array**:
 *    - Create a prefix sum array `prefixSum` where `prefixSum[i]` is the sum of `nums[0]` to `nums[i]`.
 * 2. **Window Sum Calculation**:
 *    - For each index `i` from `k` to `n-k-1`, compute the sum of the subarray from index `i-k` to `i+k` using:
 *      - `sum = prefixSum[i+k] - (i-k > 0 ? prefixSum[i-k-1] : 0)`
 * 3. **Average Computation**:
 *    - Set `result[i] = sum / (2*k + 1)` if a full window exists.
 *    - For indices where a full window cannot be formed, `result[i]` remains `-1`.
 *
 * @complexity
 * - **Time Complexity:** O(n)
 *   - Building the prefix sum array takes O(n).
 *   - Calculating the window sum for each valid index takes O(n).
 * - **Space Complexity:** O(n)
 *   - Extra space for the prefix sum and result arrays.
 *
 * @example
 * **Input:** nums = [1,3,2,6,-1,4,1,8,2], k = 3
 * **Output:** [-1,-1,2,3,2,3,-1,-1,-1]
 * **Explanation:**
 * - For index 3 (0-indexed), the window is [1,3,2,6,-1,4,1] and the average is 16/7 ≈ 2 (using integer division).
 * - Indices that cannot form a full window (i.e., first 3 and last 3 indices) are set to -1.
 *
 * **Edge Case:**
 * - If the length of `nums` is less than `2*k+1`, then no index can have a full window; return an array of `-1`s.
 */
class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        // If no window is needed, return the original array
        if (k == 0)
            return nums;

        // Build prefix sum array
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        // Prepare result array, initialized to -1
        vector<int> result(n, -1);
        // If there is no valid window, return the result as is
        if (n < 2 * k + 1)
            return result;

        // Calculate window averages for indices that have a complete window
        for (int i = k; i <= n - k - 1; i++)
        {
            int rightIdx = i + k;
            int leftIdx = i - k;
            long long sum = prefixSum[rightIdx];
            if (leftIdx > 0)
            {
                sum -= prefixSum[leftIdx - 1];
            }
            result[i] = sum / (2 * k + 1);
        }
        return result;
    }
};
