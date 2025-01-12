/**
 * @author : Rohit
 * @date   : 2025-01-12
 * @problem: Search a 2D Matrix
 * @link   : https://leetcode.com/problems/search-a-2d-matrix/
 * @level  : Medium
 *
 * @description
 * This function searches for a given target value in a 2D matrix.
 * The matrix has the following properties:
 * 1. Each row is sorted in ascending order.
 * 2. The first integer of each row is greater than the last integer of the previous row.
 *
 * @approach
 * 1. **Start at the Top-Right Corner**:
 *    - Initialize `row = 0` and `col = m - 1`, where `m` is the number of columns.
 *    - This position is ideal as it allows movement:
 *      - Downward for larger values.
 *      - Leftward for smaller values.
 * 2. **Iterate**:
 *    - While `row < n` (number of rows) and `col >= 0`:
 *      - Compare `matrix[row][col]` with `target`:
 *        - If equal, return `true`.
 *        - If less, move down (`row++`) to find larger values.
 *        - If greater, move left (`col--`) to find smaller values.
 * 3. **Return**:
 *    - If the loop ends without finding the target, return `false`.
 *
 * @complexity
 * Time Complexity: O(n + m), where `n` is the number of rows and `m` is the number of columns.
 * Space Complexity: O(1), as no additional data structures are used.
 *
 * @example
 * Input: matrix = [[1, 4, 7, 11], [2, 5, 8, 12], [3, 6, 9, 16], [10, 13, 14, 17]], target = 5
 * Output: true
 * Explanation:
 * - The target value `5` exists in the matrix.
 *
 * Input: matrix = [[1, 4, 7, 11], [2, 5, 8, 12], [3, 6, 9, 16], [10, 13, 14, 17]], target = 20
 * Output: false
 * Explanation:
 * - The target value `20` does not exist in the matrix.
 */

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        int col = m - 1;
        while (row < n && col >= 0)
        {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                row++;
            else
                col--;
        }
        return false;
    }
}