/**
 * @author : Rohit
 * @date   : 2025-01-14
 * @problem: Decode String at Index
 * @link   : https://leetcode.com/problems/decoded-string-at-index/
 * @level  : Medium
 *
 * @description
 * This function decodes a string based on the given rules and retrieves the character at the `k`th position in the expanded string.
 * - The input string `s` contains lowercase English letters and digits.
 * - Digits in the string represent repeat operations for the preceding substring.
 * - The expanded string can be extremely large, so we avoid constructing it explicitly.
 *
 * @approach
 * 1. **Calculate Total Length**:
 *    - Traverse the string to compute the effective length of the expanded string.
 *    - If the character is a letter, increase the size by 1.
 *    - If the character is a digit, multiply the size by the digit.
 * 2. **Reverse Traversal**:
 *    - Traverse the string in reverse to simulate decoding without expanding.
 *    - Use modular arithmetic (`k % size`) to locate the position of `k` in the reduced string.
 *    - If `k == 0` and the current character is a letter, return the character.
 *    - Adjust `size` based on whether the character is a letter or a digit.
 * 3. **Edge Cases**:
 *    - If `k` points to a position in a repeated block, adjust it using modulo operations.
 *
 * @complexity
 * Time Complexity: O(n), where `n` is the length of the string `s`.
 * - First traversal: Compute the total size of the expanded string.
 * - Second traversal: Reverse iterate to decode.
 * Space Complexity: O(1), as no additional data structures are used.
 *
 * @example
 * Input: s = "leet2code3", k = 10
 * Output: "o"
 * Explanation:
 * - Expanded string: "leetleetcodeleetleetcodeleetleetcode" (truncated for illustration).
 * - The 10th character is "o".
 *
 * Input: s = "ha22", k = 5
 * Output: "h"
 * Explanation:
 * - Expanded string: "hahahahaha".
 * - The 5th character is "h".
 *
 * Input: s = "a2b3c4d5e6f7g8h9", k = 1000000000
 * Output: "a"
 */

class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        int n = s.length();

        long long size = 0;

        for (char &ch : s)
        {
            if (isdigit(ch))
            { // number
                size = size * (ch - '0');
            }
            else
            {
                size += 1;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            k = k % size;

            if (k == 0 && isalpha(s[i]))
            {
                return string(1, s[i]);
            }

            if (isalpha(s[i]))
                size -= 1;
            else
                size = size / (s[i] - '0');
        }
        return "";
    }
};