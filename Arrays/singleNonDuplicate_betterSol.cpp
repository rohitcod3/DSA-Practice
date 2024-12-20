/**
 * @author : Rohit
 * @date   : 2024-12-15
 * @problem: Single Element in a Sorted Array
 * @link   : https://leetcode.com/problems/single-element-in-a-sorted-array/
 * @level  : Medium
 *
 * @description
 * This function finds the single non-duplicate element in a given sorted array `nums`.
 * It uses a frequency count approach, utilizing a hash map (vector in this case) to count occurrences of each element.
 * The first element with a frequency of 1 is returned.
 *
 * @approach
 * 1. **Find Maximum Element**:
 *    - Traverse the array to determine the maximum value in `nums` to size the hash map.
 * 2. **Count Frequencies**:
 *    - Use a hash map (vector) of size `max(nums) + 1` to count the frequency of each element in the array.
 * 3. **Find Unique Element**:
 *    - Traverse the array and return the first element with a frequency of 1.
 *
 * @limitations
 * 1. **Space Complexity**:
 *    - The space complexity depends on the range of elements in the input array (O(max(nums))).
 *    - If the maximum element in `nums` is significantly larger than the size of the array, this approach becomes inefficient and may lead to memory issues.
 * 2. **Time Complexity**:
 *    - The algorithm requires multiple passes over the array:
 *      - One pass to determine the maximum element.
 *      - Two passes for frequency counting and finding the unique element.
 *    - This results in a time complexity of ( O(n + max(nums)) ), which is suboptimal for cases where `max(nums)` is much larger than `n`.
 * 3. **Assumption of Non-Negative Values**:
 *    - This approach assumes all elements in the array are non-negative, as indices in the hash map cannot be negative.
 *    - If negative values are present, additional transformations or a different data structure (like an unordered map) would be required.
 *
 * @complexity
 * Time Complexity: O(n + max(nums)), where `n` is the size of the array and `max(nums)` is the maximum value in the array.
 * Space Complexity: O(max(nums)), for the hash map.
 *
 * @example
 * Input: nums = [1, 1, 2, 2, 3, 3, 4]
 * Output: 4
 * Explanation:
 * - The unique element in the array is 4, which occurs only once.
 *
 * Input: nums = [1, 1, 2]
 * Output: 2
 * Explanation:
 * - The unique element in the array is 2, which occurs only once.
 */

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = nums[0];
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > maxi)
            {
                maxi = max(maxi, nums[i]);
            }
        }
        vector<int> hash(maxi + 1, 0);

        for (int i = 0; i < n; i++)
        {
            hash[nums[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (hash[nums[i]] == 1)
            {
                return nums[i];
            }
        }
        return -1;
    }
};