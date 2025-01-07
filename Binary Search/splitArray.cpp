/**
 * @author : Rohit
 * @date   : 2025-01-07
 * @problem: Split Array Largest Sum
 * @link   : https://leetcode.com/problems/split-array-largest-sum/
 * @level  : Hard
 *
 * @description
 * This function splits the array `nums` into `k` non-empty subarrays such that the largest sum among the subarrays is minimized.
 *
 * The task is to return the minimized largest sum.
 *
 * @approach
 * 1. **Binary Search on Maximum Subarray Sum**:
 *    - Define the search range for the largest sum:
 *      - `low` is the maximum element in the array (minimum possible largest sum).
 *      - `high` is the sum of all elements in the array (maximum possible largest sum).
 *    - Perform binary search:
 *      - Calculate `mid = (low + high) / 2` as a potential maximum subarray sum.
 *      - Use the helper function `countSubarray` to count the number of subarrays required with this sum.
 *      - If the number of subarrays exceeds `k`, increase `low` to search for a larger sum.
 *      - Otherwise, decrease `high` to search for a smaller sum.
 * 2. **Helper Function `countSubarray`**:
 *    - Counts the number of subarrays required if the maximum allowed sum is `maxSum`.
 *    - If adding an element exceeds `maxSum`, a new subarray is started.
 *
 * @complexity
 * Time Complexity: O(n * log(sum - max)), where `n` is the size of the array, `sum` is the total sum of the array, and `max` is the maximum element.
 * - Binary search runs \( O(\log(sum - max)) \).
 * - For each value of `mid`, the `countSubarray` function iterates through the array in \( O(n) \).
 * Space Complexity: O(1), as no additional data structures are used.
 *
 * @example
 * Input: nums = [7, 2, 5, 10, 8], k = 2
 * Output: 18
 * Explanation:
 * - Split the array into [7, 2, 5] and [10, 8].
 * - The largest sum is 18, which is minimized.
 *
 * Input: nums = [1, 2, 3, 4, 5], k = 2
 * Output: 9
 * Explanation:
 * - Split the array into [1, 2, 3] and [4, 5].
 * - The largest sum is 9, which is minimized.
 */

class Solution
{
public:
    int countSubarray(vector<int> &arr, int maxSum)
    {
        int subarrays = 1;
        long long currentSum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (currentSum + arr[i] <= maxSum)
            {
                currentSum += arr[i];
            }
            else
            {
                subarrays += 1;
                currentSum = arr[i];
            }
        }
        return subarrays;
    }

    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k > n)
            return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int students = countSubarray(nums, mid);
            if (students > k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};
