/**
 * @author : Rohit
 * @date   : 2024-11-21
 * @problem: Majority Element II
 * @link   : https://leetcode.com/problems/majority-element-ii/
 * @level  : Medium
 *
 * @description
 * This function finds all elements in the array `nums` that appear more than `n/3` times,
 * where `n` is the size of the array. If no such element exists, it returns an empty vector.
 *
 * @approach
 * 1. Use a `map` to count the frequency of each element.
 * 2. For each element in the array:
 *    - Increment its count in the map.
 *    - If the count reaches the threshold `n/3 + 1`, add the element to the result list.
 *    - Stop early if the result list contains two elements (since at most two elements can meet the criteria in this problem).
 * 3. Return the result list.
 *
 * @complexity
 * Time Complexity: O(n), as we iterate through the array and perform map operations (average O(1) per operation).
 * Space Complexity: O(n), for storing the frequency of elements in the map.
 *
 * @example
 * Input: nums = [3, 2, 3]
 * Output: [3]
 * Explanation:
 * - Element 3 appears more than n/3 = 3/3 = 1 times.
 *
 * Input: nums = [1, 1, 1, 3, 3, 2, 2, 2]
 * Output: [1, 2]
 * Explanation:
 * - Elements 1 and 2 both appear more than n/3 = 8/3 = 2.66 times.
 */

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> ls;
        map<int, int> mpp;
        int n = nums.size();
        int mini = (int)(n / 3) + 1;
        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]]++;
            if (mpp[nums[i]] == mini)
            {
                ls.push_back(nums[i]);
            }
            if (ls.size() == 2)
                break;
        }
        return ls;
    }
};