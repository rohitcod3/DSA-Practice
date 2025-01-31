/**
 * @author : Rohit
 * @date   : 2025-01-29  // (Make sure to update dynamically when generating)
 * @problem: Find Closest Number to Zero
 * @link   : https://leetcode.com/problems/find-closest-number-to-zero/
 * @level  : Easy
 *
 * @description
 * Given an integer array `nums`, return the number closest to zero.
 * If there are multiple numbers with the same absolute difference from zero,
 * return the positive one.
 *
 * @approach
 * 1. **Initialize**:
 *    - Start with `closest = nums[0]`.
 * 2. **Iterate through `nums`**:
 *    - If `nums[i]` has a smaller absolute value than `closest`, update `closest`.
 *    - If `nums[i]` has the same absolute value but is positive, update `closest`.
 * 3. **Return `closest`**:
 *    - Ensures we return the smallest absolute value, favoring positive numbers.
 *
 * @complexity
 * Time Complexity: O(n), where `n` is the size of `nums` (one pass).
 * Space Complexity: O(1), as we use only a single variable.
 *
 * @example
 * **Input:** nums = [-4, -2, 1, 4, 8]
 * **Output:** 1
 * **Explanation:** 1 is the closest to zero.
 *
 * **Input:** nums = [2, -1, 1]
 * **Output:** 1
 * **Explanation:** Both -1 and 1 are equidistant from zero, returning 1.
 */

int findClosestNumber(vector<int> &nums)
{
    int n = nums.size();
    int closest = nums[0];

    for (int i = 1; i < n; i++)
    {
        // checks if the absolute val of the current no, is less than the abs val of closest
        if (abs(nums[i]) < abs(closest))
        {
            closest = nums[i];
        }
        // checks if the current val and the closest are equal and if they are it then checks if the current number is bigger that the absolute number,we are looking for positive number here
        // ex: nums=[-1000,1000] so we return 1000
        else if (abs(nums[i]) == abs(closest) && nums[i] > closest)
        {
            closest = nums[i];
        }
    }
    return closest;
}
