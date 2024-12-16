/**
 * @author : Rohit
 * @date   : 2024-12-16
 * @problem: Merge Sort Algorithm
 * @link   : Custom Implementation
 * @level  : Medium
 *
 * @description
 * This is an implementation of the merge sort algorithm. The function `mergeSort` recursively divides the array into smaller subarrays and sorts them by merging with the helper function `mS`.
 *
 * @approach
 * 1. **Divide and Conquer**:
 *    - The array is recursively divided into two halves until each subarray has one or zero elements (base case).
 * 2. **Merge Process**:
 *    - The helper function `mS` merges two sorted subarrays back into the original array in sorted order.
 *    - The merging process uses a temporary vector to store the sorted elements.
 * 3. **In-place Update**:
 *    - After merging, the sorted elements are copied back into the original array.
 *
 * @complexity
 * Time Complexity: O(n log n), where `n` is the size of the array.
 * - Each division step takes \(O(\log n)\).
 * - Each merge step takes \(O(n)\).
 * Space Complexity: O(n), for the temporary array used during merging.
 *
 * @example
 * Input: nums = [7, 4, 5, 6, 2, 3]
 * Output: [2, 3, 4, 5, 6, 7]
 * Explanation:
 * - The array is divided and sorted recursively, and then merged back into a single sorted array.
 */

void mS(vector<int> &nums, int low, int mid, int high)
{
    // we merge from low to high
    vector<int> temp;
    int n = nums.size();
    int left = low;
    int right = mid + 1;
    //[7,4,5]  [6,2,3]
    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else
        {
            temp.push_back(nums[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(nums[right]);
        right++;
    }

    for (int i = 0; i < temp.size(); i++)
    {
        nums[low + i] = temp[i];
    }
}

void mergeSort(vector<int> &nums, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    mS(nums, low, mid, high);
}