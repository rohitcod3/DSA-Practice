/**
 * @author : Rohit
 * @date   : 2025-01-15
 * @problem: Longest Common Prefix
 * @link   : https://leetcode.com/problems/longest-common-prefix/
 * @level  : Easy
 *
 * @description
 * This function finds the longest common prefix string among an array of strings `strs`.
 * If there is no common prefix, an empty string is returned.
 *
 * @approach
 * 1. **Initialize Prefix**:
 *    - Start with the first string as the initial prefix.
 * 2. **Iterative Comparison**:
 *    - Compare the current prefix with each subsequent string.
 *    - Reduce the prefix length until it matches the start of the current string.
 *    - If the prefix becomes empty, return an empty string immediately.
 * 3. **Return Result**:
 *    - After iterating through all strings, the remaining prefix is the longest common prefix.
 *
 * @complexity
 * Time Complexity: O(S), where `S` is the sum of all characters in the input strings.
 * - Each character of each string is compared at most once.
 * Space Complexity: O(1), as the operation is performed in-place.
 *
 * @example
 * Input: strs = ["flower", "flow", "flight"]
 * Output: "fl"
 *
 * Input: strs = ["dog", "racecar", "car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 */
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++)
        {
            while (strs[i].find(prefix) != 0)
            {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty())
                    return "";
            }
        }
        return prefix;
    }
};