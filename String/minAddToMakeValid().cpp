/**
 * @author : Rohit
 * @date   : 2025-02-24
 * @problem: Minimum Add to Make Parentheses Valid
 * @link   : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
 * @level  : Medium
 *
 * @description
 * Given a string `s` consisting of `'('` and `')'`, return the **minimum number of
 * parentheses** that must be added to make the string valid.
 *
 * @approach
 * **Greedy Counting Approach**
 * 1. **Use Two Counters**:
 *    - `size` (tracks unmatched `'('` parentheses).
 *    - `open` (tracks unmatched `')'` parentheses).
 * 2. **Iterate Through the String**:
 *    - If `ch == '('`, increment `size` (means we need a matching `')'`).
 *    - If `ch == ')'`:
 *      - If `size > 0`, decrement `size` (as a matching `'('` exists).
 *      - Otherwise, increment `open` (as this `')'` is unmatched).
 * 3. **Final Count**:
 *    - The answer is `size + open` (all unmatched `'('` and `')'` combined).
 *
 * @complexity
 * **Time Complexity**: O(n) → Single pass through the string.
 * **Space Complexity**: O(1) → Only two integer variables are used.
 *
 * @example
 * **Input**: s = "())"
 * **Output**: 1
 * **Explanation**: One `'('` is needed to make it valid: `"()"`.
 *
 * **Input**: s = "((("
 * **Output**: 3
 * **Explanation**: Three `')'` are needed: `"((()))"`.
 */

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int size = 0;
        int open = 0;

        for (char &ch : s)
        {
            if (ch == '(')
            {
                size++;
            }
            else if (size > 0)
            {
                size--;
            }
            else
            {
                open++;
            }
        }
        return open + size;
    }
};