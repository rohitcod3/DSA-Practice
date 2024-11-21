/**
 * @author Rohit
 * @link   https://leetcode.com/problems/two-sum/description/
 * @level  Easy
 *
 * @description
 * This function finds two indices of numbers in an array that add up to a given target.
 * It uses a hash map (unordered_map) for efficient lookup of the required complement.
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> mpp;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            int rem = target - num;

            if (mpp.find(rem) != mpp.end())
            {
                return {mpp[rem], i};
            }
            mpp[num] = i;
        }
        return {-1, -1};
    }
};
