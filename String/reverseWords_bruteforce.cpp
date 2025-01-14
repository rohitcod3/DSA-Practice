/**
 * @author : Rohit
 * @date   : 2025-01-14
 * @problem: Reverse Words in a String
 * @link   : https://leetcode.com/problems/reverse-words-in-a-string/
 * @level  : Medium
 *
 * @description
 * This function reverses the words in a given string `s`.
 * Words are separated by one or more spaces, and the result should contain only a single space between words.
 *
 * @approach (Brute-Force)
 * 1. **Split the String into Words**:
 *    - Use `stringstream` to extract individual words from the input string `s`.
 * 2. **Reverse the Order of Words**:
 *    - Append each word to the result string in reverse order.
 * 3. **Trim Extra Space**:
 *    - Remove the trailing space from the result string, if any.
 *
 * @complexity
 * Time Complexity: O(n), where `n` is the length of the input string.
 * - Splitting the string and reversing the words both take O(n).
 * Space Complexity: O(n), for storing the result string.
 *
 * @example
 * Input: s = "  hello world  "
 * Output: "world hello"
 * Explanation:
 * - After splitting: ["hello", "world"]
 * - Reversed order: "world hello"
 *
 * Input: s = "a good   example"
 * Output: "example good a"
 * Explanation:
 * - After splitting: ["a", "good", "example"]
 * - Reversed order: "example good a"
 */

class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        ;
        string token = "";
        string result = "";

        while (ss >> token)
        {
            result = token + " " + result;
        }
        if (!result.empty())
        {
            result.erase(result.length() - 1);
        }

        return result;
    }
};