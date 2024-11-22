/**
 * @author : Rohit
 * @date   : 2024-11-21
 * @problem: Longest Subarray with Sum K
 * @link   : (https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399)
 * @level  : Medium
 *
 * @description
 * This function calculates the length of the longest contiguous subarray whose sum equals `k`.
 * It uses the prefix sum and hash map technique to achieve an efficient solution.
 *
 * @complexity
 * Time Complexity: O(n) - Single traversal of the array and \(O(1)\) for each hash map operation.
 * Space Complexity: O(n) - Space for the hash map storing prefix sums.
 */

int longestSubarrayWithSumK(vector<int> a, long long k)
{
    map<long long, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];

        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        int rem = sum - k;

        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        preSumMap[sum] = i;
    }
    return maxLen;
}