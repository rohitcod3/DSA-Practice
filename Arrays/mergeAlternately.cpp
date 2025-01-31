/**
 * @author : Rohit
 * @date   : 2025-01-29  // (Ensure to update dynamically)
 * @problem: Merge Strings Alternately
 * @link   : https://leetcode.com/problems/merge-strings-alternately/
 * @level  : Easy
 *
 * @description
 * Given two strings, `word1` and `word2`, merge them alternately by taking characters from
 * each string one by one. If one string is longer, append the remaining characters to the end.
 *
 * @approach
 * 1. **Initialize Pointers (`i`, `j`)**:
 *    - Start from index `0` for both strings.
 * 2. **Alternate Merging**:
 *    - Take one character from `word1`, then one from `word2`, appending to `result`.
 * 3. **Handle Remaining Characters**:
 *    - If one string is longer, append its remaining characters to `result`.
 * 4. **Return Merged String**:
 *    - Ensures correct interleaving of characters.
 *
 * @complexity
 * Time Complexity: O(n + m), where `n` and `m` are the lengths of `word1` and `word2`, respectively.
 * Space Complexity: O(n + m), since we store the merged string.
 *
 * @example
 * **Input:** word1 = "abc", word2 = "pqr"
 * **Output:** "apbqcr"
 * **Explanation:** Characters are merged alternately.
 *
 * **Input:** word1 = "ab", word2 = "pqrs"
 * **Output:** "apbqrs"
 * **Explanation:** "rs" remains after alternating characters.
 */

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int i = 0;
        int j = 0;
        string result = "";

        while (i < word1.length() && j < word2.length())
        {
            result += word1[i];
            i++;
            result += word2[j];
            j++;
        }

        while (i < word1.length())
        {
            result += word1[i];
            i++;
        }
        while (j < word2.length())
        {
            result += word2[j];
            j++;
        }
        return result;
    }
};