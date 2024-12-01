/**
 * @author : Rohit
 * @date   : 2024-12-01
 * @problem: Longest Consecutive Sequence
 * @link   : https://leetcode.com/problems/longest-consecutive-sequence/
 * @level  : Medium
 *
 * @description
 * This function finds the length of the longest consecutive sequence of integers in the given array `nums`.
 * A consecutive sequence is defined as a sequence of numbers that can be arranged in increasing order without gaps.
 *
 * @approach
 * 1. Use an `unordered_set` to store unique elements from the input array.
 * 2. For each element in the set:
 *    - Check if it's the start of a potential sequence (i.e., no number `it - 1` exists in the set).
 *    - Count consecutive numbers starting from `it` by repeatedly checking for `it + 1` in the set.
 *    - Update the `longest` variable with the maximum sequence length found.
 * 3. Return the `longest` sequence length.
 *
 * @complexity
 * Time Complexity: O(n) - Each element is processed once for insertion into the set and once for finding consecutive elements.
 * Space Complexity: O(n) - Additional space is used for the `unordered_set`.
 *
 * @example
 * Input: nums = [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation:
 * - The longest consecutive sequence is [1, 2, 3, 4].
 * - Length: 4.
 *
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 * Explanation:
 * - The longest consecutive sequence is [0, 1, 2, 3, 4, 5, 6, 7, 8].
 * - Length: 9.
 */

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int longest = 1;
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }

        for (auto it : st)
        {
            if (st.find(it - 1) == st.end())
            {
                int count = 1;
                int x = it;
                while (st.find(x + 1) != st.end())
                {
                    x = x + 1;
                    count = count + 1;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};