/**
 * @author : Rohit
 * @date   : 2025-01-29
 * @problem: Orderly Queue
 * @link   : https://leetcode.com/problems/orderly-queue/
 * @level  : Hard
 *
 * @description
 * The problem involves rearranging a given string `s` based on the integer `k`:
 * - If `k == 1`, the only allowed operation is rotating the first character to the end.
 * - If `k > 1`, we can reorder characters freely.
 *
 * Key Difference Between `k == 1` and `k > 1`:
 *
 * **For `k > 1`:**
 * - You have enough flexibility to swap characters into any position through repeated operations.
 * - Example: With `k = 2`, you can "bubble" characters to their correct positions by moving others out of the way.
 * - This allows you to sort the entire string.
 * - Thus, sorting directly gives the lexicographically smallest string.
 *
 * **For `k == 1`:**
 * - Each operation rotates the string by one character (e.g., `"abc" → "bca" → "cab" → "abc"`).
 * - You can only generate rotations of the original string. No reordering beyond this is possible.
 * - Example: For `s = "cba"`, you can generate `["cba", "bac", "acb"]` but not `"abc"` (the sorted string).
 * - The smallest possible string is the lexicographically smallest rotation, **not the sorted string**.
 *
 * **Example Walkthrough (k == 1):**
 * - Input: `s = "cba", k = 1`
 * - Possible rotations: `["cba", "bac", "acb"]`
 * - Lexicographically smallest: `"acb"`
 * - Sorted string `"abc"` is **not** achievable through rotations.
 *
 * **Why Rotations Are Insufficient for Sorting (`k == 1`):**
 * - Rotations preserve the cyclic order of characters. You cannot break this order to sort unless the original string is already a rotation of the sorted string.
 * - For `k == 1`, the problem reduces to **finding the minimum rotation**, **not sorting**.
 *
 * **Code Logic for `k == 1`:**
 * - The code iterates through all possible rotations (by concatenating substrings).
 * - It keeps track of the smallest rotation encountered (`result = min(result, temp)`).
 * - This ensures the lexicographically smallest rotation is returned.
 *
 * **Time Complexity Analysis:**
 * - Sorting (`k > 1`): `O(n log n)`
 * - Generating rotations (`k == 1`): `O(n^2)` (Each rotation takes `O(n)`, and we check `O(n)` times).
 *
 * @complexity
 * - **Time Complexity**: `O(n log n)` for sorting when `k > 1`, `O(n^2)` for generating rotations when `k == 1`.
 * - **Space Complexity**: `O(n)` for storing the smallest rotation.
 *
 */

class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
        // simply sort and return if k > 1
        if (k > 1)
        {
            sort(begin(s), end(s));
            return s;
        }

        string result = s;

        for (int l = 1; l <= s.length() - 1; l++)
        {
            string temp = s.substr(l) + s.substr(0, l);
            result = min(result, temp);
        }

        return result;
    }
};