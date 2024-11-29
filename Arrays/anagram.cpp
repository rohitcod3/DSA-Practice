/**
 * @author : Rohit
 * @date   : 2024-11-29
 * @problem: Valid Anagram
 * @link   : https://leetcode.com/problems/valid-anagram/
 * @level  : Easy
 *
 * @description
 * This function checks whether two strings `s` and `t` are anagrams of each other.
 * Two strings are considered anagrams if they contain the same characters with the
 * same frequency, in any order.
 *
 * @approach
 * 1. If the lengths of `s` and `t` differ, they cannot be anagrams.
 * 2. Use a frequency count array for 26 lowercase English letters.
 *    - Increment the count for characters in `s`.
 *    - Decrement the count for characters in `t`.
 * 3. Use the `all_of` function to check if all counts are zero, indicating anagrams.
 *
 * @complexity
 * Time Complexity: O(n), where `n` is the length of `s` (or `t`), as we traverse each string once.
 * Space Complexity: O(1), as the frequency count array has a fixed size of 26.
 *
 */

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> count(26, 0);

        for (char &ch : s)
        {
            count[ch - 'a']++;
        }

        for (char &ch : t)
        {
            count[ch - 'a']--;
        }

        // check if all elements in count are zero
        bool allZeros = all_of(begin(count), end(count), [](int element)
                               { return element == 0; });

        return allZeros;
    }
};