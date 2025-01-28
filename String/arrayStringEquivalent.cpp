/**
 * @author : Rohit
 * @date   : 2025-01-28
 * @problem: Check If Two String Arrays are Equivalent
 * @link   : https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
 * @level  : Easy
 *
 * @description
 * This function checks if two string arrays, `word1` and `word2`, are equivalent by concatenating all strings in each array
 * and comparing the resulting concatenated strings.
 *
 * @approach
 * 1. **Concatenate Strings**:
 *    - Traverse each array (`word1` and `word2`) and concatenate all its elements into two separate strings (`first` and `second`).
 * 2. **Compare Strings**:
 *    - Check if the two concatenated strings are equal.
 * 3. **Return Result**:
 *    - Return `true` if the strings are equal, otherwise return `false`.
 *
 * @complexity
 * Time Complexity: O(n + m), where `n` is the total length of strings in `word1` and `m` is the total length of strings in `word2`.
 * - Each string in the arrays is traversed once for concatenation.
 * Space Complexity: O(n + m), for storing the concatenated strings.
 *
 * @example
 * Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
 * Output: true
 * Explanation: "ab" + "c" == "a" + "bc" -> "abc" == "abc".
 *
 * Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
 * Output: false
 * Explanation: "a" + "cb" != "ab" + "c" -> "acb" != "abc".
 */

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string first = "";
        string second = "";
        int i = 0;
        int j = 0;
        while (i < word1.size())
        {
            first += word1[i];
            i++;
        }

        while (j < word2.size())
        {
            second += word2[j];
            j++;
        }

        if (first == second)
            return true;

        return false;
    }
};