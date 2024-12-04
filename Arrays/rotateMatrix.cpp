/**
 * @author : Rohit
 * @date   : 2024-12-03
 * @problem: Rotate Image
 * @link   : https://leetcode.com/problems/rotate-image/
 * @level  : Medium
 *
 * @description
 * This function rotates a given `n x n` matrix 90 degrees clockwise in-place.
 * The rotation is performed in two steps:
 * 1. Transpose the matrix (swap rows with columns).
 * 2. Reverse each row of the transposed matrix.
 *
 * @approach
 * 1. **Transpose the matrix**:
 *    - Swap elements `matrix[i][j]` and `matrix[j][i]` for all `i` and `j` such that `j > i`.
 * 2. **Reverse each row**:
 *    - Use the `reverse` function on each row to achieve a 90-degree clockwise rotation.
 *
 * @complexity
 * Time Complexity: O(n^2) - Both transposing and reversing require O(n^2) operations for an `n x n` matrix.
 * Space Complexity: O(1) - The operation is performed in-place without using additional space.
 *
 */

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        // transpose the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // reverse every row
        for (int i = 0; i < n; i++)
        {
            // for every row is matrix[i]
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};