/**
 * @author : Rohit
 * @date   : 2025-01-29  // (Ensure to update dynamically)
 * @problem: Is Subsequence
 * @link   : https://leetcode.com/problems/is-subsequence/
 * @level  : Easy
 *
 * @description
 * This function checks if the given string `s` is a subsequence of string `t`.
 * A subsequence is formed by deleting some (or none) of the characters from `t`
 * without changing the relative order of the remaining characters.
 *
 * @approach
 * 1. **Two Pointer Technique**:
 *    - Use two pointers `k` for `s` and `j` for `t` to iterate through both strings.
 * 2. **Iterate through `t`**:
 *    - If `s[k]` matches `t[j]`, move `k` to check the next character in `s`.
 *    - Continue iterating until either `s` is fully matched or `t` is exhausted.
 * 3. **Check Completion**:
 *    - If `k` reaches the length of `s`, it means `s` is a subsequence of `t`, return `true`.
 *    - Otherwise, return `false`.
 *
 * @complexity
 * - Time Complexity: **O(m)** where `m` is the length of `t` (single pass through `t`).
 * - Space Complexity: **O(1)** since no extra space is used.
 *
 * @example
 * Input: s = "abc", t = "ahbgdc"
 * Output: true
 * Explanation:
 * - "abc" appears in "ahbgdc" as a subsequence: "a" -> "b" -> "c".
 *
 * Input: s = "axc", t = "ahbgdc"
 * Output: false
 * Explanation:
 * - "axc" does not appear in "ahbgdc" in order.
 */

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int n = students.size();

        int arr[2] = {0};
        // arr[0] count of students liking 0 sandwich
        // arr[1] count of students liking 0 sandwich

        for (int &stud : students)
        {
            arr[stud]++;
        }

        for (int i = 0; i < n; i++)
        {
            int sand = sandwiches[i];
            if (arr[sand] == 0)
            {
                return n - i;
            }

            arr[sand]--;
        }
        return 0;
    }
};