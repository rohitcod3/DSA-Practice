/**
 * @author : Rohit
 * @date   : 2025-01-05
 * @problem: Find K-th Missing Positive Number
 * @link   : https://leetcode.com/problems/kth-missing-positive-number/
 * @level  : Easy
 *
 * @description
 * This function finds the k-th missing positive number from a sorted array `arr` of unique positive integers.
 *
 * @approach
 * 1. **Binary Search**:
 *    - Use binary search to determine the position where the k-th missing positive number should be.
 *    - Define `low = 0` and `high = n - 1`.
 *    - For each midpoint `mid`, calculate the number of missing integers up to that point:
 *      - `missing = arr[mid] - (mid + 1)`.
 *    - If `missing < k`, the k-th missing number is beyond `mid`, so update `low = mid + 1`.
 *    - Otherwise, update `high = mid - 1`.
 * 2. **Calculate Result**:
 *    - After binary search, the k-th missing positive number is `k + high + 1`.
 *
 * @complexity
 * Time Complexity: O(log n), where `n` is the size of the array.
 * - Binary search takes O(log n) iterations.
 * Space Complexity: O(1), as no additional data structures are used.
 *
 * @example
 * Input: arr = [2, 3, 4, 7, 11], k = 5
 * Output: 9
 * Explanation:
 * - Missing numbers are [1, 5, 6, 8, 9, 10, ...].
 * - The 5th missing number is 9.
 *
 * Input: arr = [1, 2, 3, 4], k = 2
 * Output: 6
 * Explanation:-
 * - Missing numbers are [5, 6, 7, ...].
 * - The 2nd missing number is 6.
 */

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return k + high + 1;
    }
};