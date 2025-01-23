/**
 * @author : Rohit
 * @date   : 2025-01-23
 * @problem: Integer to Roman
 * @link   : https://leetcode.com/problems/integer-to-roman/
 * @level  : Medium
 *
 * @description
 * This function converts an integer to its Roman numeral representation.
 * - Roman numerals are based on seven symbols: `I`, `V`, `X`, `L`, `C`, `D`, and `M`.
 * - The algorithm repeatedly divides the number by predefined values and appends the corresponding Roman symbols to the result.
 *
 * @approach
 * 1. **Predefined Values and Symbols**:
 *    - Use two static vectors to store:
 *      - Values: `{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}`
 *      - Symbols: `{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}`
 * 2. **Iterate through Values**:
 *    - For each value, determine how many times it fits into the number using integer division.
 *    - Append the corresponding Roman symbol to the result for each occurrence.
 * 3. **Reduce the Number**:
 *    - Update the number by taking its remainder after division by the current value.
 * 4. **Terminate Early**:
 *    - Break the loop when the number becomes `0`.
 *
 * @complexity
 * Time Complexity: O(n), where `n` is the value of the input number. The number of iterations is proportional to the number of Roman numeral digits.
 * Space Complexity: O(1), as the result is stored in a single string.
 *
 * @example
 * Input: num = 1994
 * Output: "MCMXCIV"
 * Explanation:
 * - 1994 = 1000 (M) + 900 (CM) + 90 (XC) + 4 (IV)
 * - Roman numeral: "MCMXCIV"
 *
 * Input: num = 58
 * Output: "LVIII"
 * Explanation:
 * - 58 = 50 (L) + 5 (V) + 3 (III)
 * - Roman numeral: "LVIII"
 */

class Solution
{
public:
    string intToRoman(int num)
    {
        static vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        static vector<string> sym{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result = "";

        for (int i = 0; i < 13; i++)
        {
            if (num == 0)
                break;

            int times = num / val[i];

            while (times--)
            {
                result += sym[i];
            }

            num = num % val[i];
        }
        return result;
    }
};