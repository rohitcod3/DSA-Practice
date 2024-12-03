/**
 * @author : Rohit
 * @date   : 2024-11-21
 * @problem: Set Matrix Zeroes
 * @link   : https://leetcode.com/problems/set-matrix-zeroes/
 * @level  : Medium
 *
 * @description
 * This function modifies a given matrix in-place such that:
 * - If an element is 0, its entire row and column are set to 0.
 *
 * The function does this without using additional space for marking,
 * by leveraging the first row and column of the matrix as markers.
 *
 * @approach
 * 1. Use the first row and column of the matrix as markers:
 *    - If an element `matrix[i][j]` is 0, mark its row and column by setting:
 *      - `matrix[i][0] = 0`
 *      - `matrix[0][j] = 0`
 * 2. Use a separate variable `col0` to track if the first column should be zeroed out.
 * 3. Traverse the matrix again to update rows and columns based on the markers.
 * 4. Handle the first row and column separately based on their markers.
 *
 * @complexity
 * Time Complexity: O(n * m) - Two passes through the matrix of size `n x m`.
 * Space Complexity: O(1) - Uses the matrix itself as storage for markers.
 *
 */

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;

        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] == 0)
            {
                col0 = 0;
            }
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[0][j] = 0;
            }
        }

        if (col0 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
