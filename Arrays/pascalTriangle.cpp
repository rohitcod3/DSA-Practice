/**
 * @author : Rohit
 * @date   : 2024-12-07
 * @problem: Pascal's Triangle
 * @link   : https://leetcode.com/problems/pascals-triangle/
 * @level  : Easy
 *
 * @description
 * This function generates the first `numRows` rows of Pascal's Triangle.
 * Pascal's Triangle is defined as:
 * - The first row starts with `1`.
 * - Each subsequent row is constructed such that each element is the sum of the two elements directly above it in the previous row.
 * - The first and last elements of each row are always `1`.
 *
 * @approach
 * 1. **Helper Function** (`generateRow`):
 *    - Generates a specific row of Pascal's Triangle using the binomial coefficient formula:
 *      - `C(row, col) = C(row, col - 1) * (row - col) / col`
 *    - Pushes the calculated elements into a vector and returns the row.
 * 2. **Main Function** (`generate`):
 *    - Iteratively calls `generateRow` for each row from 1 to `numRows`.
 *    - Collects all rows into a 2D vector and returns the result.
 *
 * @complexity
 * Time Complexity:
 * - Generating a single row takes (O(row)).
 * - Generating `numRows` rows takes (O(numRows^2)), as the length of each row grows linearly.
 * Space Complexity: (O(numRows^2)), to store all rows of Pascal's Triangle.
 *
 * @example
 * Input: numRows = 5
 * Output: [[1],
 *          [1, 1],
 *          [1, 2, 1],
 *          [1, 3, 3, 1],
 *          [1, 4, 6, 4, 1]]
 */

class Solution
{
public:
    vector<int> generateRow(int row)
    {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for (int col = 1; col < row; col++)
        {
            ans = ans * (row - col);
            ans = ans / (col);
            ansRow.push_back(ans);
        }
        return ansRow;
    }
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++)
        {
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};