/**
 * @author : Rohit
 * @date   : 2025-02-05
 * @problem: Largest Positive Integer That Exists With Its Negative
 * @link   : https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/
 * @level  : Easy
 *
 * @description
 * Given an array `nums` of integers, this function finds the largest positive integer `k`
 * such that both `k` and `-k` exist in the array. If no such integer exists, return `-1`.
 *
 * @approach
 * 1. **Optimized Hashing Approach**:
 *    - Use an **array of size `2001`** (to cover numbers in the range `[-1000, 1000]`).
 *    - Traverse `nums`:
 *      - If `-num` exists in `arr`, update `result` with `max(result, abs(num))`.
 *      - Mark `num` as visited in `arr` (`arr[num + 1000] = 1`).
 * 2. **Why use `arr[2001]`?**
 *    - Since `nums` is in range `[-1000, 1000]`, we shift values by **+1000** to handle negative indices.
 *    - `arr[i] = 1` means the number `(i - 1000)` exists in `nums`.
 *
 * @complexity
 * - **Time Complexity:** **O(n)** (single pass through `nums`).
 * - **Space Complexity:** **O(1)** (fixed-size auxiliary array).
 *
 * @example
 * **Input:** nums = [-1,2,-3,3]
 * **Output:** 3
 * **Explanation:** Both `3` and `-3` exist, and `3` is the largest such number.
 */

class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {

        int n = nums.size();
        int arr[2001] = {0};

        int result = -1;

        for (int &num : nums)
        {
            if (arr[-num + 1000] == 1)
            {
                result = max(result, abs(num));
            }
            arr[num + 1000] = 1;
        }

        return result;

        return -1;
    }
};