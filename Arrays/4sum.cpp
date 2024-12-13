/**
 * @author : Rohit
 * @date   : 2024-12-13
 * @problem: 4Sum
 * @link   : https://leetcode.com/problems/4sum/
 * @level  : Medium
 *
 * @description
 * This function finds all unique quadruplets in the array `nums` such that their sum equals the given `target`.
 * A quadruplet is defined as four numbers `nums[i]`, `nums[j]`, `nums[k]`, and `nums[l]` such that:
 * - `i`, `j`, `k`, and `l` are distinct indices.
 * - `nums[i] + nums[j] + nums[k] + nums[l] = target`.
 * The result must not contain duplicate quadruplets.
 *
 * @approach
 * 1. **Sort the Array**:
 *    - Sorting simplifies the problem by allowing the use of multiple nested loops and the two-pointer technique.
 * 2. **Nested Loops**:
 *    - Use two nested loops for `i` and `j` to fix the first two numbers.
 *    - For each pair (`nums[i]`, `nums[j]`), use two pointers (`k` and `l`) to find the remaining two numbers that sum to the required value.
 * 3. **Avoid Duplicates**:
 *    - Skip duplicate elements at each level (`i`, `j`, `k`, and `l`) to ensure unique quadruplets in the result.
 * 4. **Two-Pointer Technique**:
 *    - Start `k` at `j + 1` and `l` at the end of the array.
 *    - Adjust pointers based on the current sum compared to the `target`:
 *      - If the sum equals the target, add the quadruplet to the result.
 *      - If the sum is less than the target, increment `k`.
 *      - If the sum is greater than the target, decrement `l`.
 *
 * @complexity
 * Time Complexity: O(n^3), where `n` is the size of the array. Sorting takes \(O(n \log n)\) and the nested loops plus two-pointer traversal take \(O(n^3)\).
 * Space Complexity: O(1), excluding the space used for the result vector.
 *
 * @example
 * Input: nums = [1, 0, -1, 0, -2, 2], target = 0
 * Output: [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]
 * Explanation:
 * - Quadruplets [-2, -1, 1, 2], [-2, 0, 0, 2], and [-1, 0, 0, 1] all sum to 0.
 *
 * Input: nums = [2, 2, 2, 2, 2], target = 8
 * Output: [[2, 2, 2, 2]]
 * Explanation:
 * - Only one quadruplet sums to 8: [2, 2, 2, 2].
 */

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int k = j + 1;
                int l = n - 1;

                while (k < l)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;

                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sum < target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
            }
        }

        return ans;
    }
};
