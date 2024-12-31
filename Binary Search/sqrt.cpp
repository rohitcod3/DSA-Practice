/**
 * @author : Rohit
 * @date   : 2025-01-01
 * @problem: Sqrt(x)
 * @link   : https://leetcode.com/problems/sqrtx/
 * @level  : Easy
 *
 * @description
 * This function calculates the integer square root of a non-negative integer `x`.
 * The integer square root is the largest integer `y` such that \( y^2 \leq x \).
 *
 * The function uses a binary search algorithm to find the square root efficiently.
 *
 * @approach
 * 1. **Binary Search**:
 *    - Use two pointers, `low` and `high`, initialized to `1` and `x`, respectively.
 *    - Calculate the middle value `mid = low + (high - low) / 2` to avoid overflow.
 *    - Compute `val = mid * mid`:
 *      - If `val <= x`, move `low = mid + 1` to search in the higher range.
 *      - Otherwise, move `high = mid - 1` to search in the lower range.
 * 2. **Return Result**:
 *    - The variable `high` will hold the largest integer whose square is less than or equal to `x`.
 *
 * @complexity
 * Time Complexity: O(log x), where `x` is the input value.
 * - The search space is halved in each iteration.
 * Space Complexity: O(1), as no additional data structures are used.
 *
 * @example
 * Input: x = 8
 * Output: 2
 * Explanation:
 * - The square root of `8` is approximately `2.828`, and its integer part is `2`.
 *
 * Input: x = 16
 * Output: 4
 * Explanation:
 * - The square root of `16` is `4`.
 */

class Solution
{
public:
    int mySqrt(int x)
    {

        int low = 1, high = x;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long val = (mid * mid);
            if (val <= x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return high;
    }
};