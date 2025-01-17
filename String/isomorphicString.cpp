/**
 * @author : Rohit
 * @date   : 2025-01-17
 * @problem: Isomorphic Strings
 * @link   : https://leetcode.com/problems/isomorphic-strings/
 * @level  : Easy
 *
 * @description
 * This function checks if two strings `s` and `t` are isomorphic.
 * Two strings are isomorphic if the characters in `s` can be replaced to get `t`,
 * while maintaining the order of characters and ensuring no two characters map to the same character.
 *
 * @approach
 * 1. **Two Hash Maps**:
 *    - Use two hash maps (`mpp1` and `mpp2`) to store the character mappings from `s` to `t` and vice versa.
 *    - Traverse through the strings and check:
 *      - If a character in `s` is already mapped but doesn't match the corresponding character in `t`, return false.
 *      - Similarly, if a character in `t` is already mapped but doesn't match the corresponding character in `s`, return false.
 *    - Update the mappings for characters in both strings.
 * 2. **Final Result**:
 *    - If all characters are mapped consistently, return true.
 *
 * @complexity
 * Time Complexity: O(n), where `n` is the length of the strings.
 * - Each character is processed once.
 * Space Complexity: O(n), for the two hash maps storing the character mappings.
 *
 * @example
 * Input: s = "egg", t = "add"
 * Output: true
 * Explanation:
 * - 'e' maps to 'a', 'g' maps to 'd', and the mapping is consistent.
 *
 * Input: s = "foo", t = "bar"
 * Output: false
 * Explanation:
 * - 'o' cannot map to both 'a' and 'r'.
 *
 * Input: s = "paper", t = "title"
 * Output: true
 * Explanation:
 * - 'p' maps to 't', 'a' maps to 'i', 'p' maps to 't', 'e' maps to 'l', and 'r' maps to 'e'.
 */
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> mpp1;
        unordered_map<char, char> mpp2;

        int n = s.length();

        for (int i = 0; i < n; i++)
        {

            char ch1 = s[i];
            char ch2 = t[i];

            if (mpp1.find(ch1) != mpp1.end() && mpp1[ch1] != ch2 || mpp2.find(ch2) != mpp2.end() && mpp2[ch2] != ch1)
            {
                return false;
            }

            mpp1[ch1] = ch2;
            mpp2[ch2] = ch1;
        }
        return true;
    }
};