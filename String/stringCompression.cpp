/**
 * @author : Rohit
 * @date   : 2025-01-25
 * @problem: String Compression
 * @link   : https://leetcode.com/problems/string-compression/
 * @level  : Medium
 *
 * @description
 * This function compresses a list of characters `chars` in-place such that:
 * - Consecutive duplicate characters are replaced by a single occurrence followed by their count (if greater than 1).
 * - The function returns the new length of the compressed list.
 * - Compression is done without allocating extra space for another array.
 *
 * @approach
 * 1. **Two Pointers**:
 *    - Use two pointers: `i` to traverse the input list and `index` to modify the list in place.
 * 2. **Counting Duplicates**:
 *    - For each unique character, calculate the number of consecutive occurrences.
 *    - Replace the character at `index` with the current character.
 *    - If the count > 1, append the count as individual digits to `chars`.
 * 3. **In-place Modification**:
 *    - Modify the list in place and maintain the compressed characters and counts at the beginning of the array.
 *
 * @complexity
 * Time Complexity: O(n), where `n` is the size of the array.
 * - Traverses the array once to compute counts and compress.
 * Space Complexity: O(1), as the compression is done in place.
 *
 * @example
 * Input: chars = ['a','a','b','b','c','c','c']
 * Output: 6
 * Explanation:
 * - Compressed array: ['a','2','b','2','c','3'] (length = 6).
 *
 * Input: chars = ['a']
 * Output: 1
 * Explanation:
 * - Compressed array: ['a'] (length = 1).
 *
 * Input: chars = ['a','b','c']
 * Output: 3
 * Explanation:
 * - Compressed array: ['a','b','c'] (length = 3).
 */

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();

        int index = 0;
        int i = 0;

        while (i < n)
        {
            char curr_char = chars[i];
            int count = 0;

            // find count of duplicates
            while (i < n && chars[i] == curr_char)
            {
                count++;
                i++;
            }

            // do the assignment

            chars[index] = curr_char;
            index++;

            if (count > 1)
            {
                string count_str = to_string(count);

                for (char &ch : count_str)
                {
                    chars[index] = ch;
                    index++;
                }
            }
        }
        return index;
    }
};