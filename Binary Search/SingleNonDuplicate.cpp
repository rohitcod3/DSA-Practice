/**
 * @author : Rohit
 * @date   : 2024-12-30
 * @problem: Single Element in a Sorted Array
 * @link   : https://leetcode.com/problems/single-element-in-a-sorted-array/
 * @level  : Medium
 *
 * @description
 * This function finds the single non-duplicate element in a sorted array `nums`, where every other element appears exactly twice.
 * The array is sorted, and the function uses a binary search approach to efficiently locate the unique element.
 *
 * @approach
 * 1. **Handle Edge Cases**:
 *    - If the array contains only one element, return it.
 *    - If the first or last element is unique, return it.
 * 2. **Binary Search**:
 *    - Use two pointers, `low` and `high`, initialized to `1` and `n - 2`, respectively.
 *    - Calculate the middle index `mid` as `(low + high) / 2`.
 *    - Check if `nums[mid]` is the unique element:
 *      - If `nums[mid] != nums[mid + 1]` and `nums[mid] != nums[mid - 1]`, return `nums[mid]`.
 *    - Determine which half to search next:
 *      - If `mid` is even and `nums[mid] == nums[mid + 1]` or `mid` is odd and `nums[mid] == nums[mid - 1]`, search the right half (`low = mid + 1`).
 *      - Otherwise, search the left half (`high = mid - 1`).
 * 3. **Return Result**:
 *    - If no unique element is found during the loop, return `-1` (though this should not occur in valid input).
 *
 * @complexity
 * Time Complexity: O(log n), where `n` is the size of the array.
 * - The search space is halved in each iteration.
 * Space Complexity: O(1), as no additional data structures are used.
 *
 * @example
 * Input: nums = [1, 1, 2, 3, 3, 4, 4, 8, 8]
 * Output: 2
 * Explanation:
 * - The unique element is `2`.
 *
 * Input: nums = [3, 3, 7, 7, 10, 11, 11]
 * Output: 10
 * Explanation:
 * - The unique element is `10`.
 */

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];
        int low = 1, high = n - 2;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
            {
                return nums[mid];
            }

            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};