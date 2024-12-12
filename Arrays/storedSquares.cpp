/**
 * @author : Rohit
 * @date   : 2024-12-12
 * @problem: Squares of a Sorted Array
 * @link   : https://leetcode.com/problems/squares-of-a-sorted-array/
 * @level  : Easy
 *
 * @description
 * This function takes a sorted array `nums` (in non-decreasing order) and returns a new array where each element is the square of the corresponding element in `nums`, sorted in non-decreasing order.
 *
 * @approach
 * 1. **Two-Pointer Technique**:
 *    - Use two pointers: `i` starting at the leftmost index and `j` starting at the rightmost index.
 *    - Compare the squares of the elements at `i` and `j`.
 *    - Place the larger square at the current position `k` in the result array and move the corresponding pointer inward.
 * 2. Fill the result array (`ans`) from the end (index `k = n - 1`) to the beginning, ensuring the output is sorted.
 *
 * @complexity
 * Time Complexity: O(n), where `n` is the size of the array. Each element is processed exactly once.
 * Space Complexity: O(n), for the output array `ans`.
 *
 * @example
 * Input: nums = [-4, -1, 0, 3, 10]
 * Output: [0, 1, 9, 16, 100]
 * Explanation:
 * - Squaring the elements gives: [16, 1, 0, 9, 100].
 * - Sorting the squared elements gives: [0, 1, 9, 16, 100].
 *
 * Input: nums = [-7, -3, 2, 3, 11]
 * Output: [4, 9, 9, 49, 121]
 * Explanation:
 * - Squaring the elements gives: [49, 9, 4, 9, 121].
 * - Sorting the squared elements gives: [4, 9, 9, 49, 121].
 */

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> ans(n);

        int i = 0, j = n - 1;
        int k = n - 1;

        while (k >= 0)
        {
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];
            if (a > b)
            {
                ans[k] = a;
                i++;
            }
            else
            {
                ans[k] = b;
                j--;
            }
            k--;
        }
        return ans;
    }
};
