/**
 * @author : Rohit
 * @date   : 2025-01-04
 * @problem: Smallest Divisor Given a Threshold
 * @link   : https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
 * @level  : Medium
 *
 * @description
 * This function finds the smallest divisor `div` such that the sum of all elements in the array `nums`, divided by `div` (rounded up), does not exceed the given `threshold`.
 *
 * The function uses binary search to efficiently determine the minimum possible divisor.
 *
 * @approach
 * 1. **Binary Search on Divisor**:
 *    - Initialize `low = 1` and `high = max(nums)` as the range for possible divisors.
 *    - Calculate `mid = (low + high) / 2`.
 * 2. **Sum Calculation with Helper Function**:
 *    - Use the helper function `sumByD` to calculate the sum of elements in `nums` divided by `mid`, rounded up.
 *    - If the sum ≤ `threshold`, update `high = mid - 1` to search for a smaller divisor.
 *    - Otherwise, update `low = mid + 1` to increase the divisor.
 * 3. **Return Result**:
 *    - The smallest divisor is stored in `low` after binary search completes.
 *
 * @helper_function
 * - **sumByD(arr, div)**:
 *   - Calculates the sum of all elements in `arr` divided by `div`, rounded up using `ceil`.
 *
 * @complexity
 * Time Complexity: O(n * log(max)), where `n` is the size of the array, and `max` is the maximum element in `nums`.
 * - Binary search runs in O(log(max)).
 * - For each divisor, the sum is computed in O(n).
 * Space Complexity: O(1), as no additional data structures are used.
 *
 * @example
 * Input: nums = [1, 2, 5, 9], threshold = 6
 * Output: 5
 * Explanation:
 * - Possible divisors: 1, 2, 3, 4, 5, ...
 * - For div = 5, sum = ⌈1/5⌉ + ⌈2/5⌉ + ⌈5/5⌉ + ⌈9/5⌉ = 1 + 1 + 1 + 2 = 5.
 * - 5 ≤ threshold, so the smallest divisor is 5.
 *
 * Input: nums = [44, 22, 33, 11, 1], threshold = 10
 * Output: 8
 * Explanation:
 * - For div = 8, sum = ⌈44/8⌉ + ⌈22/8⌉ + ⌈33/8⌉ + ⌈11/8⌉ + ⌈1/8⌉ = 6 + 3 + 5 + 2 + 1 = 17.
 * - Reduce divisor to minimize sum below threshold.
 */

class Solution
{
public:
    int sumByD(vector<int> &arr, int div)
    {
        int sum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            sum = sum + ceil((double)(arr[i] / (double)(div)));
        }
        return sum;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (sumByD(nums, mid) <= threshold)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};