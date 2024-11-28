/**
 * @author : Rohit
 * @date   : 2024-11-28
 * @problem: Next Permutation
 * @link   : https://leetcode.com/problems/next-permutation/
 * @level  : Medium
 *
 * @description
 * This function computes the next lexicographical permutation of an array of integers.
 * If no greater permutation is possible (the array is sorted in descending order),
 * the array is rearranged into the smallest possible order (ascending order).
 *
 * @approach
 * 1. Find the "pivot" element:
 *    - Traverse the array from right to left to find the first element (`nums[ind]`)
 *      that is smaller than the element immediately after it (`nums[ind + 1]`).
 * 2. Handle descending order:
 *    - If no pivot is found (`ind == -1`), reverse the array to obtain the smallest order.
 * 3. Find the smallest element greater than the pivot:
 *    - Traverse the array from right to left to find the smallest number greater than `nums[ind]`.
 *    - Swap `nums[ind]` with this number.
 * 4. Reverse the suffix:
 *    - Reverse the subarray to the right of `ind` to rearrange it into ascending order.
 *
 * @complexity
 * Time Complexity: O(n) - Single traversal to find the pivot, another traversal to find the swap element,
 * and one more traversal to reverse the suffix.
 * Space Complexity: O(1) - In-place manipulation of the array.
 *
 * @example
 * Input: nums = [1, 3, 2]
 * Output: [2, 1, 3]
 * Explanation:
 * - Pivot: nums[0] = 1 (index 0).
 * - Swap: nums[0] = 1 with nums[2] = 2.
 * - Reverse suffix: Reverse [3, 1] to [1, 3].
 * - Result: [2, 1, 3].
 *
 * Input: nums = [3, 2, 1]
 * Output: [1, 2, 3]
 * Explanation:
 * - No pivot found (descending order).
 */

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int ind = -1;
        int n = nums.size();

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                ind = i;
                break;
            }
        }

        if (ind == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n - 1; i > ind; i--)
        {
            if (nums[i] > nums[ind])
            {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        reverse(nums.begin() + ind + 1, nums.end());
    }
};
