/**
 * @author : Rohit
 * @date   : 2025-01-15
 * @problem: Reverse Words in a String
 * @link   : https://leetcode.com/problems/reverse-words-in-a-string/
 * @level  : Medium
 *
 * @description
 * This function reverses the order of words in a given string `s`.
 * It removes extra spaces (leading, trailing, and between words)
 * and ensures that words are separated by a single space in the output.
 *
 * @approach
 * 1. **Reverse Entire String**:
 *    - Reverse the entire string to bring the last word to the front.
 * 2. **Process Each Word**:
 *    - Traverse the string, identify each word, and copy it to its correct position.
 *    - Reverse each word in-place.
 *    - Add a space after each word.
 * 3. **Remove Trailing Space**:
 *    - Trim the extra space at the end after processing all words.
 *
 * @complexity
 * Time Complexity: O(n), where `n` is the length of the string.
 * - Reversing the string takes O(n).
 * - Processing and reversing each word takes O(n).
 * Space Complexity: O(1), as the operations are performed in-place.
 *
 * @example
 * Input: "  hello world  "
 * Output: "world hello"
 *
 * Input: "a good   example"
 * Output: "example good a"
 */
class Solution
{
public:
    string reverseWords(string s)
    {

        reverse(s.begin(), s.end());

        int i = 0, l = 0, r = 0, n = s.length();

        while (i < n)
        {

            while (i < n && s[i] != ' ')
            {
                s[r] = s[i];
                i++;
                r++;
            }

            if (l < r)
            {
                reverse(s.begin() + l, s.begin() + r);
                s[r] = ' ';
                r++;
                l = r;
            }

            i++;
        }

        if (r > 0 && s[r - 1] == ' ')
        {
            s = s.substr(0, r - 1);
        }

        return s;
    }
};
