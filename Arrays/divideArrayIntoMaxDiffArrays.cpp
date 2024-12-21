/**
 * @author : Rohit
 * @date   : 2024-12-15
 * @problem: Divide Array into Groups of Size 3 with Difference Constraint
 * @link   : https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/
 * @level  : Medium
 *
 * @description
 * This function divides an array `nums` into groups of size 3 such that:
 * - The difference between the largest and smallest numbers in each group is less than or equal to `k`.
 * - If such a division is not possible, the function returns an empty result.
 *
 * @approach
 * 1. **Sort the Array**:
 *    - Sort the array to ensure elements in each group are as close as possible in value.
 * 2. **Iterate Over Groups of Size 3**:
 *    - Traverse the sorted array in steps of 3.
 *    - For each group (`nums[i], nums[i+1], nums[i+2]`), check if the difference between the largest and smallest numbers (`nums[i+2] - nums[i]`) exceeds `k`.
 * 3. **Validation**:
 *    - If the difference exceeds `k` for any group, return an empty result.
 * 4. **Construct Result**:
 *    - Push valid groups into the result vector.
 *
 * @complexity
 * Time Complexity: O(n log n), where `n` is the size of the array.
 * - Sorting takes ( O(n log n) ).
 * - Iterating through the array takes O(n).
 * Space Complexity: O(n), for the result vector.
 *
 * @example
 * Input: nums = [3, 6, 1, 2, 5, 4], k = 2
 * Output: [[1, 2, 3], [4, 5, 6]]
 * Explanation:
 * - After sorting: [1, 2, 3, 4, 5, 6].
 * - Group 1: [1, 2, 3] (difference = 3 - 1 = 2, valid).
 * - Group 2: [4, 5, 6] (difference = 6 - 4 = 2, valid).
 *
 * Input: nums = [1, 5, 9, 13], k = 3
 * Output: []
 * Explanation:
 * - After sorting: [1, 5, 9, 13].
 * - Group 1: [1, 5, 9] (difference = 9 - 1 = 8, invalid).
 * - Return an empty result as no valid grouping is possible.
 */

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<vector<int>> result;

        sort(begin(nums), end(nums));

        for (int i = 0; i < n; i += 3)
        {
            // i, i+1, i+2
            if (nums[i + 2] - nums[i] > k)
            {
                return {};
            }

            result.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }

        return result;
    }
};