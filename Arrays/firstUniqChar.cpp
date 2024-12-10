/**
 * @author : Rohit
 * @date   : 2024-12-10
 * @problem: First Unique Character in a String
 * @link   : https://leetcode.com/problems/first-unique-character-in-a-string/
 * @level  : Easy
 *
 * @description
 * This function finds the first non-repeating character in a given string `s`
 * and returns its index. If no unique character exists, it returns -1.
 *
 * @approach
 * 1. Use an array of size 26 (`arr`) to count the frequency of each character:
 *    - The index of the array corresponds to the character ('a' to 'z').
 * 2. Perform a first pass through the string to populate the frequency array.
 * 3. Perform a second pass through the string to check for the first character
 *    with a frequency of 1 in the array.
 * 4. Return the index of the first unique character, or -1 if no such character exists.
 *
 * @complexity
 * Time Complexity: O(n), where `n` is the length of the string. The string is traversed twice.
 * Space Complexity: O(1), as the frequency array is of fixed size (26 for lowercase letters).
 *
 * @example
 * Input: s = "leetcode"
 * Output: 0
 * Explanation: The first unique character is 'l', located at index 0.
 *
 * Input: s = "loveleetcode"
 * Output: 2
 * Explanation: The first unique character is 'v', located at index 2.
 *
 * Input: s = "aabb"
 * Output: -1
 * Explanation: No unique character exists in the string.
 */

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int arr[26] = {0};
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            arr[ch - 'a']++;
        }

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (arr[ch - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};