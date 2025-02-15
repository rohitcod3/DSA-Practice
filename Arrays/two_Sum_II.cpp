/**
 * @author : Rohit
 * @date   : 2025-02-15
 * @problem: Two Sum II - Input Array Is Sorted
 * @link   : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 * @level  : Medium
 *
 * @description
 * This function finds two numbers in a sorted array "numbers" that add up to a given target and returns
 * their 1-indexed positions. It uses a two-pointer approach to efficiently identify the correct pair.
 *
 * @approach
 * 1. **Initialize Two Pointers**:
 *    - Set `low = 0` and `high = n - 1`, where `n` is the number of elements.
 * 2. **Traverse the Array**:
 *    - While `low < high`:
 *      - If `numbers[low] + numbers[high] == target`, return `{low + 1, high + 1}`.
 *      - If the sum is less than the target, increment `low`.
 *      - Otherwise, decrement `high`.
 * 3. **Return Result**:
 *    - If no valid pair is found, return `{-1, -1}` (though the problem guarantees a solution).
 *
 * @complexity
 * - **Time Complexity:** O(n) — each element is processed at most once.
 * - **Space Complexity:** O(1) — no extra space is required.
 *
 * @example
 * **Input:** numbers = [2, 7, 11, 15], target = 9
 * **Output:** [1, 2]
 * **Explanation:** 2 + 7 = 9, so the function returns indices 1 and 2.
 */

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();

        int low = 0;
        int high = n - 1;

        while (low < high)
        {
            if ((numbers[low] + numbers[high]) == target)
            {
                return {low + 1, high + 1};
            }
            else if ((numbers[low] + numbers[high]) < target)
            {
                low++;
            }
            else
            {
                high--;
            }
        }
        return {-1, -1};
    }
};