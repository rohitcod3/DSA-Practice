/**
 * @author : Rohit
 * @date   : 2025-01-20
 * @problem: Maximum Nesting Depth of Parentheses
 * @link   : https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
 * @level  : Easy
 *
 * @description
 * This function calculates the maximum nesting depth of valid parentheses in the input string `s`.
 * The nesting depth of parentheses is the maximum number of nested open parentheses encountered at any point in the string.
 *
 * @approach
 * 1. **Track Current Depth**:
 *    - Use a variable `depth` to track the current depth of open parentheses.
 *    - Increment `depth` for every '(' encountered and decrement it for every ')'.
 * 2. **Update Maximum Depth**:
 *    - Maintain another variable `maxDepth` to store the highest value of `depth` during traversal.
 * 3. **Edge Cases**:
 *    - If the string does not contain any parentheses, the result is `0`.
 *
 * @complexity
 * Time Complexity: O(n), where `n` is the length of the input string.
 * - The string is traversed once to compute the maximum depth.
 * Space Complexity: O(1), as no additional data structures are used apart from a few variables.
 *
 * @example
 * Input: s = "(1+(2*3)+((8)/4))+1"
 * Output: 3
 * Explanation:
 * - The maximum depth is 3 due to the nesting "((8)/4)".
 *
 * Input: s = "(1)+((2))+(((3)))"
 * Output: 3
 * Explanation:
 * - The maximum depth is 3 due to the triple nested parentheses.
 *
 * Input: s = "1+(2*3)/(2-1)"
 * Output: 1
 * Explanation:
 * - The maximum depth is 1 as there is no nesting.
 */

class Solution
{
public:
    int maxDepth(string s)
    {
        int depth = 0;
        int maxDepth = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                depth++;
                maxDepth = max(maxDepth, depth);
            }
            else if (c == ')')
            {
                depth--;
            }
        }

        return maxDepth;
    }
};