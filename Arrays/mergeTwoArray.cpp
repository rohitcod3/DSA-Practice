/**
 * @author : Rohit
 * @date   : 2024-12-15
 * @problem: Merge Two Sorted Arrays into Separate Arrays
 * @link   : https://leetcode.com/problems/merge-sorted-array/description/
 * @level  : Easy
 *
 * @description
 * This function merges two sorted arrays, `arr1` and `arr2`, into a single sorted array.
 * It then modifies the original arrays such that:
 * - `arr1` contains the first `n` smallest elements of the merged array.
 * - `arr2` contains the remaining `m` largest elements of the merged array.
 *
 * @approach(BRUTEFORCE APPROACH)
 * 1. **Two-Pointer Technique**:
 *    - Use two pointers (`left` for `arr1` and `right` for `arr2`) to merge the arrays.
 *    - Compare the current elements from both arrays and add the smaller one to a temporary result array (`arr3`).
 *    - Move the pointer corresponding to the smaller element.
 * 2. **Fill Remaining Elements**:
 *    - Once one of the arrays is fully processed, add the remaining elements of the other array to `arr3`.
 * 3. **Update Original Arrays**:
 *    - Copy the first `n` elements of `arr3` back to `arr1`.
 *    - Copy the next `m` elements of `arr3` back to `arr2`.
 *
 * @complexity
 * Time Complexity: O(n + m), where `n` and `m` are the sizes of `arr1` and `arr2`, respectively.
 * Space Complexity: O(n + m), for the temporary array `arr3`.
 *
 * @example
 * Input:
 * arr1 = [1, 4, 7], n = 3
 * arr2 = [2, 5, 6], m = 3
 * Output:
 * arr1 = [1, 2, 4]
 * arr2 = [5, 6, 7]
 */

void mergeArrays(vector<int> arr1, int n, vector<int> arr2, int m)
{
    int left = 0;
    int right = 0;
    int index = 0;
    vector<int> arr3(n + m);

    while (left < n && right < m)
    {
        if (arr2[right] <= arr1[left])
        {
            arr3[index] = arr2[right];
            right++, index++;
        }
        else
        {
            arr3[index] = arr1[left];
            index++, left++;
        }
    }

    while (left < n)
    {
        arr3[index] = arr1[left];
        index++, left++;
    }
    while (right < m)
    {
        arr3[index] = arr2[right];
        index++, right++;
    }

    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr3[i];
    }

    for (int i = 0; i < m; i++)
    {
        arr2[i] = arr3[n + i];
    }
}