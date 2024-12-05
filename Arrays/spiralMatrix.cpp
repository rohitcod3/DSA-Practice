/**
 * @author : Rohit
 * @date   : 2024-12-04
 * @problem: Spiral Matrix
 * @link   : https://leetcode.com/problems/spiral-matrix/
 * @level  : Medium
 *
 * @description
 * This function returns the elements of a 2D matrix in a spiral order.
 * The traversal starts from the top-left corner and proceeds layer by layer in the following order:
 * - Move right across the top row.
 * - Move down the rightmost column.
 * - Move left across the bottom row.
 * - Move up the leftmost column.
 * This continues until all elements are visited.
 *
 * @approach
 * 1. Initialize four boundaries: `top`, `bottom`, `left`, and `right`.
 * 2. Use a loop to traverse the matrix layer by layer:
 *    - Traverse the top row from `left` to `right`, then increment `top`.
 *    - Traverse the rightmost column from `top` to `bottom`, then decrement `right`.
 *    - If `top <= bottom`, traverse the bottom row from `right` to `left`, then decrement `bottom`.
 *    - If `left <= right`, traverse the leftmost column from `bottom` to `top`, then increment `left`.
 * 3. Continue until all boundaries are crossed (`top > bottom` or `left > right`).
 * 4. Return the collected elements.
 *
 * @complexity
 * Time Complexity: O(n * m) - All elements in the `n x m` matrix are visited exactly once.
 * Space Complexity: O(n * m)- vector ans used to store the result
 *
 */

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = m - 1;
        int top = 0, bottom = n - 1;
        vector<int> ans;

        while (top <= bottom && left <= right)
        {
            // right
            for (int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
            }
            bottom--;
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};