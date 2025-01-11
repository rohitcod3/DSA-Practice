/**
 * @author : Rohit
 * @date   : 2025-01-11
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
 * 1. **Flatten the Matrix Conceptually**:
 *    - Treat the 2D matrix as a 1D sorted array by calculating indices using:
 *      - `row = mid / m` and `col = mid % m`, where `m` is the number of columns.
 * 2. **Binary Search**:
 *    - Use two pointers, `low` and `high`, initialized to `0` and `(n * m) - 1` respectively, where `n` is the number of rows and `m` is the number of columns.
 *    - At each iteration:
 *      - Compute `mid` as `(low + high) / 2`.
 *      - Access the matrix value using `matrix[row][col]`.
 *      - Compare the value with `target` and adjust pointers accordingly:
 *        - If equal, return `true`.
 *        - If less, search the right half (`low = mid + 1`).
 *        - If greater, search the left half (`high = mid - 1`).
 * 3. **Return**:
 *    - If the loop ends without finding the target, return `false`.
 *
 * @complexity
 * Time Complexity: O(log(n * m)), where `n` is the number of rows and `m` is the number of columns.
 * Space Complexity: O(1), as no additional data structures are used.
 *
 * @example
 * Input: matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], target = 3
 * Output: true
 * Explanation:
 * - The target value `3` exists in the matrix.
 *
 * Input: matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], target = 13
 * Output: false
 * Explanation:
 * - The target value `13` does not exist in the matrix.
 */

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = (n * m) - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int row = mid / m;
            int col = mid % m;
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};