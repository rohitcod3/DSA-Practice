/**
 * @author : Rohit
 * @date   : 2024-12-20
 * @problem: Move Zeroes
 * @link   : https://leetcode.com/problems/move-zeroes/
 * @level  : Easy
 *
 * @description
 * This function moves all the zeroes in the input array `nums` to the end while maintaining the relative order of the non-zero elements.
 * It uses an in-place approach to minimize space usage and ensure efficiency.
 *
 * @approach
 * 1. **Find First Zero**:
 *    - Traverse the array to find the first occurrence of zero and store its index in `j`.
 *    - If no zero is found, the array is already sorted, and we return.
 * 2. **In-Place Swapping**:
 *    - Start from the index `j + 1` and look for non-zero elements.
 *    - Swap the non-zero element at `i` with the element at `j` and increment `j`.
 * 3. **Result**:
 *    - All non-zero elements are moved to the left, and zeroes are pushed to the right.
 *
 * @complexity
 * Time Complexity: O(n), where `n` is the size of the array.
 * - Single traversal to find the first zero and another traversal to rearrange elements.
 * Space Complexity: O(1), as no additional data structures are used.
 *
 * @example
 * Input: nums = [0, 1, 0, 3, 12]
 * Output: [1, 3, 12, 0, 0]
 * Explanation:
 * - Non-zero elements [1, 3, 12] are moved to the front, followed by two zeroes.
 *
 * Input: nums = [0]
 * Output: [0]
 * Explanation:
 * - The array contains a single zero, so no change is needed.
 */

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int j = -1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                j = i;
                break;
            }
        }

        if (j == -1)
            return;

        for (int i = j + 1; i < n; i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};