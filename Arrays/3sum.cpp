/**
 * @author : Rohit
 * @date   : 2024-12-11
 * @problem: 3Sum
 * @link   : https://leetcode.com/problems/3sum/
 * @level  : Medium
 *
 * @description
 * This function finds all unique triplets in the array `nums` that sum up to zero.
 * A triplet is defined as three numbers `nums[i]`, `nums[j]`, and `nums[k]` such that:
 * - `i`, `j`, and `k` are distinct indices.
 * - `nums[i] + nums[j] + nums[k] = 0`.
 * The result must not contain duplicate triplets.
 *
 * @approach
 * 1. **Sort the Array**:
 *    - Sorting simplifies the problem by allowing the use of the two-pointer technique.
 * 2. **Iterate Through the Array**:
 *    - For each element `nums[i]`, use two pointers (`j` and `k`) to find two other numbers that sum with `nums[i]` to zero.
 *    - Skip duplicates to ensure unique triplets.
 * 3. **Two-Pointer Technique**:
 *    - Start `j` at `i + 1` and `k` at the end of the array.
 *    - Adjust pointers based on the sum:
 *      - If the sum is less than zero, increment `j`.
 *      - If the sum is greater than zero, decrement `k`.
 *      - If the sum equals zero, add the triplet to the result and adjust pointers to skip duplicates.
 *
 * @complexity
 * Time Complexity: O(n^2), where `n` is the size of the array. Sorting takes O(n log n) and the two-pointer traversal takes O(n^2).
 * Space Complexity: O(1), excluding the space used for the result vector.
 *
 * @example
 * Input: nums = [-1, 0, 1, 2, -1, -4]
 * Output: [[-1, -1, 2], [-1, 0, 1]]
 * Explanation:
 * - The triplets [-1, -1, 2] and [-1, 0, 1] sum to zero.
 * - Other combinations either don't sum to zero or are duplicates.
 *
 * Input: nums = [0, 1, 1]
 * Output: []
 * Explanation: No triplets sum to zero.
 */

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                {
                    j++;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};