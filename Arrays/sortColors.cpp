/**
 * @author : Rohit
 * @date   : 2024-11-22
 * @problem: Sort Array of 0s, 1s, and 2s
 * @link   : (https://leetcode.com/problems/sort-colors/M)
 * @level  : Easy
 *
 * @complexity
 * Used the Dutch National Flag algorithm for efficient sorting.
 * Time Complexity: O(n) - Single pass through the array.
 * Space Complexity: O(1) - In-place sorting without extra space.
 * Handles arrays with mixed 0s, 1s, and 2s effectively.
 */

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
