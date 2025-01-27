/**
 * @author : Rohit
 * @date   : 2025-01-27
 * @problem: Count and Say
 * @link   : https://leetcode.com/problems/count-and-say/
 * @level  : Medium
 *
 * @description
 * The function generates the `n`th term of the "Count and Say" sequence.
 * - The sequence starts with "1".
 * - Each subsequent term describes the previous term as a count of consecutive characters.
 *
 * @approach
 * 1. **Recursive Generation**:
 *    - For the base case `n == 1`, return "1".
 *    - For any other `n`, recursively compute `countAndSay(n-1)` to get the previous term.
 * 2. **Count Consecutive Characters**:
 *    - Traverse the string, counting consecutive characters.
 *    - For each group, append the count followed by the character to the result.
 * 3. **Return Result**:
 *    - Return the constructed string after processing all characters.
 *
 * @complexity
 * Time Complexity: O(n * m), where `n` is the number of terms and `m` is the average length of the terms.
 * - Each recursive call processes the string for the previous term.
 * Space Complexity: O(n), for the recursive stack.
 *
 * @example
 * Input: n = 1
 * Output: "1"
 *
 * Input: n = 4
 * Output: "1211"
 * Explanation:
 * - Term 1: "1"
 * - Term 2: "11" (one 1)
 * - Term 3: "21" (two 1s)
 * - Term 4: "1211" (one 2, one 1)
 */

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";

        string say = countAndSay(n - 1);

        string result = "";

        for (int i = 0; i < say.length(); i++)
        {

            char ch = say[i];

            int count = 1;

            while (i < say.length() - 1 && say[i] == say[i + 1])
            {
                count++;
                i++;
            }
            result += to_string(count) + string(1, ch);
        }
        return result;
    }
};