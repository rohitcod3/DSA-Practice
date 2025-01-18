/**
 * @author : Rohit
 * @date   : 2025-01-18
 * @problem: Rotate String
 * @link   : https://leetcode.com/problems/rotate-string/
 * @level  : Easy
 *
 * @description
 * This function checks if the string `goal` can be obtained by rotating the string `s`.
 * Rotation of a string involves moving the first character to the end repeatedly.
 *
 * @approach
 * 1. **Length Check**:
 *    - If the lengths of `s` and `goal` are not equal, return false immediately.
 * 2. **Concatenation and Substring Search**:
 *    - Concatenate `s` with itself, forming `s + s`.
 *    - Check if `goal` is a substring of this concatenated string using `find`.
 *    - If it is, return true; otherwise, return false.
 *
 * @complexity
 * Time Complexity: O(n + m), where `n` and `m` are the lengths of `s` and `goal`, respectively.
 * - Concatenation takes O(n), and substring search takes O(n + m).
 * Space Complexity: O(n), for storing the concatenated string.
 *
 * @example
 * Input: s = "abcde", goal = "cdeab"
 * Output: true
 * Explanation:
 * - "cdeab" is a rotation of "abcde" by moving "ab" to the end.
 *
 * Input: s = "abcde", goal = "abced"
 * Output: false
 * Explanation:
 * - "abced" cannot be formed by any rotation of "abcde".
 */
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int n = s.length();
        int m = goal.length();

        if (n != m)
        {
            return false;
        }

        if ((s + s).find(goal) != string::npos)
        {
            return true;
        }
        return false;
    }
};