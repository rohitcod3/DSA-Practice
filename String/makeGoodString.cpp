/**
 * @author : Rohit
 * @date   : 2025-01-30
 * @problem: Make The String Great
 * @link   : https://leetcode.com/problems/make-the-string-great/
 * @level  : Easy
 *
 * @description
 * The problem requires us to repeatedly remove adjacent characters if they have the same letter but different cases.
 * - If two adjacent characters differ by exactly 32 (i.e., 'a' and 'A'), they are removed.
 * - Continue this process until no more such pairs exist.
 *
 * **Example Walkthrough:**
 * - Input: `"leEeetcode"`
 * - Step 1: `"lEeetcode"` → Remove `"Ee"` → `"leetcode"`
 * - Step 2: `"leetcode"` → No more adjacent case-difference pairs.
 * - Output: `"leetcode"`
 *
 * **Approach:**
 * - Use a string `result` as a stack.
 * - Iterate through the string:
 *   - If the last character in `result` differs by 32 from the current character (uppercase/lowercase pair), remove the last character.
 *   - Otherwise, append the current character to `result`.
 *
 * **Key Observations:**
 * - **ASCII Difference**: 'a' (97) and 'A' (65) differ by 32 (`'a' - 'A' = 32`).
 * - Using `result.back()` efficiently allows us to compare adjacent elements in `O(1)`.
 *
 * **Time Complexity Analysis:**
 * - Each character is processed **at most once** and pushed/popped at most once: **O(n)**.
 * - Space Complexity: **O(n)** (worst case if no removals).
 *
 * @complexity
 * - **Time Complexity**: `O(n)`, where `n` is the length of the string.
 * - **Space Complexity**: `O(n)`, due to the stack-like `result` string.
 *
 */
class Solution
{
public:
    string makeGood(string s)
    {

        string result = "";

        for (char &ch : s)
        {
            if (!result.empty() && (result.back() + 32 == ch || result.back() - 32 == ch))
            {
                result.pop_back();
            }
            else
            {
                result.push_back(ch);
            }
        }
        return result;
    }
};