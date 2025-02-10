/**
 * @author : Rohit
 * @date   : 2025-02-10
 * @problem: Find All Duplicates in an Array
 * @link   : https://leetcode.com/problems/find-all-duplicates-in-an-array/
 * @level  : Medium
 *
 * @description
 * Given an integer array `nums` of size `n` where elements are in the range `[1, n]`,
 * the function returns **all the duplicate elements** appearing **twice**.
 *
 * @approach
 * **Index Marking Technique (In-Place Solution)**
 * - **Iterate through the array** and treat `nums[i]` as an index by computing `idx = abs(nums[i]) - 1`.
 * - **Mark the number at `idx` negative** if it's positive (to track that we have seen it).
 * - **If the number at `idx` is already negative**, it means we've seen `num` before, so we **add `num` to the result**.
 *
 * **Why Does This Work?**
 * - Since all numbers are in the range `[1, n]`, we can use **index marking** instead of extra space.
 * - Negative marking ensures **O(1) extra space** and **O(n) time complexity**.
 *
 * @complexity
 * - **Time Complexity:** O(n) - Each element is processed once.
 * - **Space Complexity:** O(1) - Only output vector is used.
 *
 * @example
 * **Input:**
 * ```
 * nums = [4,3,2,7,8,2,3,1]
 * ```
 * **Output:**
 * ```
 * [2, 3]
 * ```
 * **Explanation:**
 * - Marking indices and checking duplicates reveals `2` and `3` appear twice.
 *
 * @edge-cases
 * - **No duplicates:** `[1, 2, 3, 4] → Output: []`
 * - **All elements are the same:** `[2, 2, 2, 2] → Output: [2]`
 * - **Already sorted:** `[1, 1, 2, 3, 4, 5, 5] → Output: [1, 5]`
 */

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> result;

        for (int i = 0; i < n; i++)
        {
            int num = abs(nums[i]);

            int idx = num - 1;
            if (nums[idx] < 0)
            {
                result.push_back(num);
            }
            else
            {
                nums[idx] *= -1;
            }
        }
        return result;
    }
};