/**
 * @author : Rohit
 * @date   : 2025-01-10
 * @problem: Row with Maximum Number of 1s
 * @link   : https://leetcode.com/problems/richest-customer-wealth/
 * @level  : Easy
 *
 * @description
 * This function finds the row in a binary matrix `mat` that contains the maximum number of 1s.
 *
 * The approach involves counting the number of 1s in each row and tracking the row index that has the maximum count.
 *
 * @approach
 * 1. **Iterate Through Each Row**:
 *    - For each row in the matrix, initialize a counter `cnt` to count the number of 1s.
 *    - Traverse each column of the row and increment `cnt` when a 1 is encountered.
 * 2. **Track the Maximum Count**:
 *    - Keep track of the maximum count of 1s (`maxCnt`) and the row index (`ind`) that achieves this maximum.
 * 3. **Return the Result**:
 *    - Once all rows have been processed, return the index of the row with the maximum number of 1s along with the count of 1s.
 *
 * @complexity
 * Time Complexity: O(n * m), where `n` is the number of rows and `m` is the number of columns in `mat`.
 * Space Complexity: O(1), as no extra space is used except for a few variables.
 *
 * @example
 * Input: mat = [[0,1,1],[1,0,1],[1,1,0]]
 * Output: [1, 2]
 * Explanation:
 * - Row 1 contains two 1s, which is the maximum count in the matrix.
 * - Hence, the row index 1 and maximum count 2 is returned.
 */

class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int ind = -1;

        int maxCnt = -1;

        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    cnt++;
                }
            }
            if (cnt > maxCnt)
            {
                maxCnt = cnt;
                ind = i;
            }
        }
        return {ind, maxCnt};
    }
};