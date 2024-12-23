/**
 * @author : Rohit
 * @date   : 2024-12-15
 * @problem: Binary Search
 * @link   : https://leetcode.com/problems/binary-search/
 * @level  : Easy
 *
 * @description
 * This function implements the binary search algorithm to find a target value in a sorted array `nums`.
 * If the target exists, it returns the index of the target value.
 * Otherwise, it returns `-1`.
 *
 * @complexity
 * Time Complexity: O(log n), where `n` is the size of the array.
 * - The search space is halved in each iteration.
 * Space Complexity: O(1), as no additional data structures are used.
 *
 * @example
 * Input: nums = [-1, 0, 3, 5, 9, 12], target = 9
 * Output: 4
 * Explanation:
 * - The target value `9` is found at index `4`.
 *
 * Input: nums = [-1, 0, 3, 5, 9, 12], target = 2
 * Output: -1
 * Explanation:
 * - The target value `2` is not present in the array.
 */

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            else if (target > nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};