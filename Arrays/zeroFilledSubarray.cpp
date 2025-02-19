/**
 * @author : Rohit
 * @date   : 2025-02-19
 * @problem: Number of Zero-Filled Subarrays
 * @link   : https://leetcode.com/problems/number-of-zero-filled-subarrays/
 * @level  : Medium
 *
 * @description
 * This function counts the number of contiguous subarrays within the input array `nums` that are filled entirely with zeros.
 *
 * For each contiguous block of zeros of length L, there are (L*(L+1))/2 zero-filled subarrays.
 *
 * @approach
 * 1. **Traverse the Array:**
 *    - Iterate through `nums` while maintaining a counter `temp_cnt` for the length of the current contiguous block of zeros.
 * 2. **Count Zero-Filled Subarrays:**
 *    - When a non-zero is encountered or at the end of the array, add (temp_cnt*(temp_cnt+1))/2 to the result counter.
 * 3. **Return the Total Count:**
 *    - Return the accumulated count of zero-filled subarrays.
 *
 * @complexity
 * - **Time Complexity:** O(n), where n is the number of elements in `nums`.
 * - **Space Complexity:** O(1), as the algorithm uses a constant amount of extra space.
 *
 * @example
 * **Input:** nums = [0, 0, 1, 0]
 * **Output:** 4
 * **Explanation:**
 * - For the first two zeros: (2*(2+1))/2 = 3 subarrays ([0], [0], [0,0])
 * - For the zero at the end: (1*(1+1))/2 = 1 subarray ([0])
 * - Total = 3 + 1 = 4.
 */
class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        int n = nums.size();
        long long cnt = 0;
        int i = 0;
        long long temp_cnt = 0;
        while (i < n)
        {
            if (nums[i] != 0)
            {
                cnt += (temp_cnt * (temp_cnt + 1)) / 2;
                temp_cnt = 0;
                i++;
            }
            else if (i < n && nums[i] == 0)
            {
                temp_cnt++;
                i++;
            }
        }
        cnt += (temp_cnt * (temp_cnt + 1)) / 2;
        return cnt;
    }
};
