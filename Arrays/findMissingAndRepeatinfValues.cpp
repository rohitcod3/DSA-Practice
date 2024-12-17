/**
 * @author : Rohit
 * @date   : 2024-12-15
 * @problem: Find Missing and Repeated Values in a Grid
 * @link   : https://leetcode.com/problems/find-missing-and-repeated-values/description/
 * @level  : Easy
 *
 * @description
 * This function identifies the missing and repeated values in an `n x n` grid of integers, where the integers range from `1` to `n^2`.
 * - One value in the grid is repeated, and another is missing.
 * - The function uses mathematical formulas to calculate:
 *    - Sum of first `n^2` natural numbers (SN)
 *    - Sum of squares of first `n^2` natural numbers (S2N)
 *    - Sum (S) and square sum (S2) of all elements in the grid.
 *
 * @approach
 * 1. **Mathematical Precomputation**:
 *    - Compute the expected sum of the first `n^2` numbers: `SN = (n^2 * (n^2 + 1)) / 2`.
 *    - Compute the expected sum of squares of the first `n^2` numbers: `S2N = (n^2 * (n^2 + 1) * (2 * n^2 + 1)) / 6`.
 * 2. **Actual Computation**:
 *    - Traverse the grid and compute the actual sum (S) and square sum (S2) of grid elements.
 * 3. **Solve for Missing and Repeating Values**:
 *    - `val1 = S - SN` gives `x - y` (difference between repeating and missing values).
 *    - `val2 = S2 - S2N` gives `x^2 - y^2`, which simplifies to `(x + y) * (x - y)`.
 *    - Solve for `x` (repeating) and `y` (missing) using the equations:
 *      - `x = (val1 + val2) / 2`
 *      - `y = x - val1`
 *
 * @complexity
 * Time Complexity: O(n^2), where `n` is the size of the grid. The grid is traversed once to calculate the sum and square sum.
 * Space Complexity: O(1), as only constant space is used.
 *
 * @example
 * Input:
 * grid = [[1, 2], [2, 4]]
 * Output:
 * [2, 3]
 * Explanation:
 * - The value `2` is repeated, and the missing value is `3`.
 *
 * Input:
 * grid = [[3, 1], [4, 4]]
 * Output:
 * [4, 2]
 * Explanation:
 * - The value `4` is repeated, and the missing value is `2`.
 */

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        long long n = grid.size();
        long long total = n * n; // Total elements in the grid

        long long SN = (total * (total + 1)) / 2;
        long long S2N = (total * (total + 1) * (2 * total + 1)) / 6;

        long long S = 0, S2 = 0; // Sum and square sum of grid elements

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                S += grid[i][j];
                S2 += (long long)grid[i][j] * grid[i][j];
            }
        }

        // val1 = x - y (difference of repeating and missing)
        long long val1 = S - SN;

        // val2 = x^2 - y^2 = (x + y) * (x - y) => val2 = S2 - S2N
        long long val2 = S2 - S2N;
        val2 = val2 / val1; // val2 = x + y

        // Solving for x (repeating) and y (missing)
        long long x = (val1 + val2) / 2; // Repeating value
        long long y = x - val1;          // Missing value

        return {(int)x, (int)y};
    }
};
