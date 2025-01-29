/**
 * @author : Rohit
 * @date   : 2025-01-14
 * @problem: Check If Two String Arrays are Equivalent
 * @link   : https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
 * @level  : Easy
 *
 * @description
 * This function checks if two string arrays, `word1` and `word2`, are equivalent by simulating the traversal of their concatenated strings
 * without explicitly concatenating them.
 *
 * @approach
 * 1. **Simultaneous Traversal**:
 *    - Use two pointers, `el1` and `el2`, to iterate through the arrays `word1` and `word2`.
 *    - Use `i` and `j` to iterate through the characters of the strings within `word1` and `word2`.
 * 2. **Character-by-Character Comparison**:
 *    - Compare the characters of `word1[el1]` and `word2[el2]`.
 *    - If the characters mismatch, return `false`.
 * 3. **Move Pointers**:
 *    - Increment `i` and `j` for character traversal.
 *    - Reset `i` or `j` and move `el1` or `el2` to the next string when the end of a string in `word1` or `word2` is reached.
 * 4. **Final Check**:
 *    - Ensure both arrays are fully traversed (`el1 == n` and `el2 == m`) before returning `true`.
 *
 * @complexity
 * Time Complexity: O(n + m), where `n` is the total length of strings in `word1` and `m` is the total length of strings in `word2`.
 * - Each character in `word1` and `word2` is traversed once.
 * Space Complexity: O(1), as no additional space is used for concatenation.
 *
 * @example
 * Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
 * Output: true
 * Explanation: Traversal verifies "ab" + "c" == "a" + "bc".
 *
 * Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
 * Output: false
 * Explanation: Traversal verifies "a" + "cb" != "ab" + "c".
 */

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        int i = 0;
        int j = 0;
        int el1 = 0;
        int el2 = 0;
        int n = word1.size();
        int m = word2.size();

        while (el1 < n && el2 < m)
        {
            while (i < word1[el1].size() && j < word2[el2].size() && word1[el1][i] == word2[el2][j])
            {
                i++;
                j++;
            }

            if (i < word1[el1].size() && j < word2[el2].size() && word1[el1][i] != word2[el2][j])
            {
                return false;
            }

            if (i == word1[el1].size())
            {
                i = 0;
                el1++;
            }

            if (j == word2[el2].size())
            {
                j = 0;
                el2++;
            }
        }
        return el1 == n && el2 == m;
    }
};