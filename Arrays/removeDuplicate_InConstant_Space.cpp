/**
 * @author : Rohit
 * @date   : 2025-01-29  // (Ensure to update dynamically)
 * @problem: Remove Duplicates from Sorted Array
 * @link   : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * @level  : Easy
 *
 * @description
 * Given a sorted array `nums`, remove the duplicates **in-place** such that each element appears only once.
 * The relative order of the elements must be maintained. The function returns the new length of the array after the removal.
 *
 * @approach
 *
 * **Brute-Force Approach:**
 * 1. Create an empty vector `result`.
 * 2. Iterate through `nums` and add the first element to `result`.
 * 3. For each subsequent element, if it is different from the previous one, append it to `result`.
 * 4. Copy the `result` vector back into `nums`.
 * 5. Return the size of `result`.
 *    - Time Complexity: O(n)
 *    - Space Complexity: O(n)
 *
 * **Two-Pointer Optimal Approach:**
 * 1. Use two pointers `i` and `j`:
 *    - `i` tracks the position of the last unique element.
 *    - `j` iterates through the array.
 * 2. If `nums[j]` is not equal to `nums[i]`, increment `i` and set `nums[i] = nums[j]`.
 * 3. Return `i + 1` as the new length.
 *    - Time Complexity: O(n)
 *    - Space Complexity: O(1)
 *
 * @example
 * **Input:** nums = [0,0,1,1,1,2,2,3,3,4]
 * **Output:** 5, with the first five elements of nums modified to [0,1,2,3,4]
 */

// Brute-Force Sol
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> result;
        result.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1])
            {
                result.push_back(nums[i]);
            }
        }

        for (int i = 0; i < result.size(); i++)
        {
            nums[i] = result[i];
        }

        return result.size();
    }
};

// Two-Pointer Optimal Sol
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();

        int i = 0;
        int j = 1;

        while (j < n)
        {

            if (nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
            else
            {
                j++;
            }
        }
        return i + 1;
    }
};