/**
 * @author : Rohit
 * @date   : 2024-12-18
 * @problem: Count Inversions in an Array
 * @link   : https://www.geeksforgeeks.org/counting-inversions/
 * @level  : Hard
 *
 * @description
 * This function calculates the number of **inversions** in an array using a modified merge sort algorithm.
 * An inversion is a pair of indices (i, j) such that:
 * - `i < j` and `arr[i] > arr[j]`.
 *
 * @approach
 * 1. **Divide and Conquer**:
 *    - The array is recursively divided into two halves using merge sort.
 * 2. **Count Inversions**:
 *    - During the merge step, when an element from the right half is smaller than an element from the left half,
 *      it contributes to `(mid - left + 1)` inversions (all remaining elements in the left half).
 * 3. **Merge Step**:
 *    - Merge the two sorted halves while counting the number of inversions.
 * 4. **Combine**:
 *    - The total number of inversions is the sum of inversions in the left half, the right half, and during merging.

 * @complexity
 * Time Complexity: O(n log n), where `n` is the size of the array.
 * - Merge sort divides the array \( O(\log n) \) times and processes each division in \( O(n) \).
 * Space Complexity: O(n), for the temporary array used during the merge step.
 *
 * @example
 * Input: arr = [5, 3, 2, 4, 1]
 * Output: 8
 * Explanation:
 * Inversions are: (5,3), (5,2), (5,4), (5,1), (3,2), (3,1), (2,1), (4,1)
 */

class Solution
{
public:
    int merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        int cnt = 0;
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                cnt += (mid - left + 1);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }

        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high)
    {
        int cnt = 0;
        if (low >= high)
            return cnt;
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);
        return cnt;
    }

    int inversionCount(vector<int> &arr)
    {
        int n = arr.size();
        return mergeSort(arr, 0, n - 1);
    }
};