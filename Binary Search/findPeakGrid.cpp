/**
 * @author : Rohit
 * @date   : 2025-01-13
 * @problem: Find a Peak Element in a 2D Grid
 * @link   : https://leetcode.com/problems/find-a-peak-element-in-a-2d-grid/
 * @level  : Medium
 *
 * @description
 * A peak element in a 2D grid is an element that is strictly greater than its neighbors.
 * This function finds any peak element using binary search on columns.
 *
 * @approach
 * 1. **Binary Search on Columns**:
 *    - Define `low` and `high` as the first and last column indices.
 *    - In each iteration:
 *      - Find the column `mid`.
 *      - Identify the maximum element in column `mid` using `maxElement`.
 *    - Compare the element `(maxRow, mid)` with its neighbors:
 *      - If it is greater than both neighbors, return its coordinates.
 *      - If the left neighbor is greater, search the left submatrix (`high = mid - 1`).
 *      - Otherwise, search the right submatrix (`low = mid + 1`).
 * 2. **Edge Cases**:
 *    - Handle boundary columns carefully to avoid out-of-bounds access.
 *    - If no peak exists, return `{-1, -1}`.
 *
 * @complexity
 * Time Complexity:
 * - Finding the maximum element in a column: O(n).
 * - Binary search on columns: O(log(m)).
 * - Total: O(n * log(m)).
 *
 * Space Complexity:
 * - O(1), as no additional data structures are used.
 *
 * @example
 * Input: mat = [[1, 4], [3, 2]]
 * Output: {0, 1}
 * Explanation:
 * - The element at (0, 1) (value 4) is greater than its neighbors.
 *
 * Input: mat = [[10, 20, 15], [21, 30, 14], [7, 16, 32]]
 * Output: {1, 1}
 * Explanation:
 * - The element at (1, 1) (value 30) is greater than its neighbors.
 */

int maxElement(vector<vector<int>>&arr, int n, int m, int col){
    int maxValue = -1;
    int ind = -1;
    for(int i=0;i<n;i++){
        if(arr[i][col] > maxValue){
            maxValue = arr[i][col];
            ind = i;
        }
    }
    return ind;
}

int findPeakGrid(vector<vector<int>>&mat){
    int n=mat.size();
    int m=mat[0].size();
    int low=0;
    int high=m-1;

    while(low<=high){
        int mid = (low+high)/2;
        int maxRow = maxElement(mat, n, m, mid);
        int left = mid - 1 > 0 ? mat[maxRow][mid-1] : -1;
        int right = mid + 1 < m ? mat[maxRow][mid+1] : -1;
        if( mat[maxRow][mid] > left && mat[maxRow][mid] >right){
            return{maxRow, mid};
        } else if(mat[maxRow][mid] < left){
            high= mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return {-1,-1};
}