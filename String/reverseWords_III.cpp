/**
 * @author : Rohit
 * @date   : 2025-01-14
 * @problem: Reverse Words in a String III
 * @link   : https://leetcode.com/problems/reverse-words-in-a-string-iii/
 * @level  : Easy
 *
 * @description
 * This function reverses each word in the input string `s` while maintaining the order of the words.
 * A word is defined as a contiguous sequence of non-space characters, and the words are separated by single spaces.
 *
 * @approach
 * 1. **Iterate Through the String**:
 *    - Traverse the string character by character.
 * 2. **Identify Word Boundaries**:
 *    - When a non-space character is encountered, identify the start (`i`) and end (`j`) of the word using a while loop.
 * 3. **Reverse Each Word**:
 *    - Reverse the portion of the string from `i` to `j` using the `reverse` function.
 *    - Move the pointer `i` to `j` to continue checking for the next word.
 * 4. **Return the Modified String**:
 *    - After reversing all words, return the updated string.
 *
 * @complexity
 * Time Complexity: O(n), where `n` is the length of the input string.
 * - Each character is processed at most twice (once for identifying boundaries and once for reversing).
 * Space Complexity: O(1), as the reversal is done in-place.
 *
 * @example
 * Input: s = "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * Explanation:
 * - Each word is reversed while maintaining the order of words in the string.
 *
 * Input: s = "God Ding"
 * Output: "doG gniD"
 */

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.length();

        for (int i = 0; i < n; i++)
        {

            if (s[i] != ' ')
            {
                int j = i;
                while (j < n && s[j] != ' ')
                {
                    j++;
                }
                reverse(begin(s) + i, begin(s) + j);
                i = j;
            }
        }
        return s;
    }
};