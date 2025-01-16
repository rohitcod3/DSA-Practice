/**
 * @author : Rohit
 * @date   : 2025-01-16
 * @problem: Largest Odd Number in String
 * @link   : https://leetcode.com/problems/largest-odd-number-in-string/
 * @level  : Easy
 *
 * @description
 * This function finds the largest odd number that can be formed by taking a non-empty prefix of the string `num`.
 * If no odd number exists, it returns an empty string.
 *
 * @approach
 * 1. **Traverse from Right to Left**:
 *    - Iterate through the string `num` starting from the last character.
 *    - Check if the character represents an odd number.
 *    - If an odd number is found, return the substring from the start to the current position (inclusive).
 * 2. **Handle Edge Cases**:
 *    - If no odd number is found, return an empty string.
 *
 * @complexity
 * Time Complexity: O(n), where `n` is the length of the string `num`.
 * - The string is traversed once from right to left.
 * Space Complexity: O(1), as no extra space is used apart from variables.
 *
 * @example
 * Input: num = "35427"
 * Output: "35427"
 *
 * Input: num = "4206"
 * Output: ""
 * Explanation: No odd numbers are present.
 *
 * Input: num = "52"
 * Output: "5"
 */
class Solution
{
public:
    string largestOddNumber(string num)
    {
        int n = num.length();

        for (int i = n - 1; i >= 0; i--)
        {
            if ((num[i] - '0') % 2 != 0)
            {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};