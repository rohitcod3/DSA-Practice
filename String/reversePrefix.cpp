/**
 * @author : Rohit
 * @date   : 2025-02-04
 * @problem: Reverse Prefix of Word
 * @link   : https://leetcode.com/problems/reverse-prefix-of-word/
 * @level  : Easy
 *
 * @description
 * Given a string `word` and a character `ch`, this function reverses the prefix
 * of `word` up to and including the first occurrence of `ch`. If `ch` is not
 * present, the word remains unchanged.
 *
 * @approach
 * 1. **Find the First Occurrence of `ch`**:
 *    - Iterate through `word` to find the index of `ch`.
 * 2. **Reverse the Prefix**:
 *    - Swap characters from `0` to the found index to reverse the prefix.
 * 3. **Return the Modified String**:
 *    - If `ch` is found, return the reversed prefix combined with the rest of `word`.
 *    - If `ch` is not found, return `word` unchanged.
 *
 * @complexity
 * - Time Complexity: **O(n)**, where `n` is the length of `word`, as we perform one pass to find `ch` and another for reversal.
 * - Space Complexity: **O(1)**, since the reversal is done in place without extra memory.
 *
 * @example
 * Input: word = "abcdefd", ch = 'd'
 * Output: "dcbaefd"
 * Explanation:
 * - The first occurrence of 'd' is at index 3.
 * - The prefix "abcd" is reversed to "dcba".
 * - The result is "dcbaefd".
 */

class Solution
{
public:
    string reverse(string &word, int i, int j)
    {
        while (i < j)
        {
            swap(word[i], word[j]);
            i++;
            j--;
        }
        return word;
    }

    string reversePrefix(string word, char ch)
    {
        int n = word.size();
        int ind = -1;
        for (int i = 0; i < n; i++)
        {
            if (word[i] == ch)
            {
                ind = i;
                break;
            }
        }
        string result = reverse(word, 0, ind);
        return result;
    }
};