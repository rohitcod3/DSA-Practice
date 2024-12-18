/**
 * @author : Rohit
 * @date   : 2024-12-18
 * @problem: Reverse Pairs (Count Important Pairs)
 * @link   : https://leetcode.com/problems/reverse-pairs/
 * @level  : Hard
 *
 * @description
 * This function calculates the number of **reverse pairs** in an array using a modified merge sort algorithm.
 * A reverse pair is defined as a pair \( (i, j) \) such that:
 * - \( i < j \)
 * - \( nums[i] > 2 \times nums[j] \)
 *
 * @approach
 * 1. **Divide and Conquer**:
 *    - The array is recursively divided into two halves using merge sort.
 * 2. **Count Reverse Pairs**:
 *    - During the merge step, the function `countPairs` counts reverse pairs by:
 *      - Iterating through the left half.
 *      - Counting elements in the right half that satisfy \( nums[i] > 2 \times nums[j] \).
 * 3. **Merge Step**:
 *    - The two sorted halves are merged in the `merge` function while maintaining order.
 * 4. **Combine**:
 *    - The total number of reverse pairs is the sum of reverse pairs in the left half, right half, and during merging.

 * @complexity
 * Time Complexity: O(n log n), where `n` is the size of the array.
 * - Merge sort divides the array \( O(\log n) \) times and processes each division in \( O(n) \).
 * Space Complexity: O(n), for the temporary array used during the merge step.
 *
 * @example
 * Input: nums = [1, 3, 2, 3, 1]
 * Output: 2
 * Explanation:
 * Reverse pairs are:
 * - (3, 1) at indices (1, 4).
 * - (3, 1) at indices (3, 4).
 *
 * Input: nums = [2, 4, 3, 5, 1]
 * Output: 3
 * Explanation:
 * Reverse pairs are:
 * - (4, 1) at indices (1, 4).
 * - (3, 1) at indices (2, 4).
 * - (5, 1) at indices (3, 4).
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

    int countPairs(vector<int> &arr, int low, int mid, int high)
    {
        int cnt = 0;
        int right = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (right <= high && (long long)arr[i] > 2 * (long long)arr[right])
                right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }
    int mergeSort(vector<int> &arr, int low, int high)
    {
        if (low >= high)
            return 0;
        int cnt = 0;
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);
        return cnt;
    }
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};