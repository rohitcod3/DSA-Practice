/**
 * @author : Rohit
 * @date   : 2024-12-15
 * @problem: Find the Duplicate Number
 * @link   : https://leetcode.com/problems/find-the-duplicate-number/
 * @level  : Medium
 *
 * @description
 * This function finds the duplicate number in an array `nums` of size `n + 1`, where:
 * - The array contains integers in the range [1, n].
 * - There is exactly one duplicate number, but it may appear multiple times.
 *
 * The function uses Floyd's Tortoise and Hare (Cycle Detection) algorithm to efficiently detect the duplicate.
 *
 * @approach
 * 1. **Cycle Detection**:
 *    - Treat the array as a linked list where the value at each index points to the next index.
 *    - Use two pointers:
 *      - `slow` moves one step at a time.
 *      - `fast` moves two steps at a time.
 *    - A cycle exists due to the duplicate number, and the meeting point of `slow` and `fast` confirms the cycle.
 * 2. **Finding the Start of the Cycle**:
 *    - Reset `slow` to the start of the array.
 *    - Move both `slow` and `fast` one step at a time until they meet.
 *    - The meeting point is the duplicate number.
 *
 * @complexity
 * Time Complexity: O(n), where `n` is the size of the array.
 * - Each pointer traversal is linear in time.
 * Space Complexity: O(1), as no additional space is used.
 *
 * @example
 * Input: nums = [1, 3, 4, 2, 2]
 * Output: 2
 * Explanation:
 * - The duplicate number is `2`.
 *
 * Input: nums = [3, 1, 3, 4, 2]
 * Output: 3
 * Explanation:
 * - The duplicate number is `3`.
 */

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        int slow = nums[0];
        int fast = nums[0];

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};