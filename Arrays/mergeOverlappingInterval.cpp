/**
 * @author : Rohit
 * @date   : 2024-11-21
 * @problem: Merge Intervals
 * @link   : https://leetcode.com/problems/merge-intervals/
 * @level  : Medium
 *
 * @description
 * This function takes a list of intervals `arr` and merges all overlapping intervals.
 * It returns the merged intervals in sorted order by their start times.
 *
 * @approach
 * 1. **Sort the Intervals**:
 *    - Sort the intervals by their start time (`arr[i][0]`) to ensure they are processed in order.
 * 2. **Iterate Through the Sorted Intervals**:
 *    - If the result list `ans` is empty or the current interval does not overlap with the last interval in `ans`, add it to `ans`.
 *    - If the current interval overlaps with the last interval in `ans`, merge them by updating the end time of the last interval to the maximum of their end times.
 * 3. **Return the Result**:
 *    - The merged intervals are returned in sorted order.
 *
 * @complexity
 * Time Complexity: O(n log n), where `n` is the number of intervals. Sorting the intervals takes \(O(n \log n)\), and merging takes \(O(n)\).
 * Space Complexity: O(n), for storing the merged intervals in the result vector.
 *
 * @example
 * Input: arr = [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation:
 * - Intervals [1, 3] and [2, 6] overlap and are merged into [1, 6].
 * - Remaining intervals [8, 10] and [15, 18] do not overlap and remain as is.
 *
 * Input: arr = [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation:
 * - Intervals [1, 4] and [4, 5] overlap and are merged into [1, 5].
 */

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            if (ans.empty() || arr[i][0] > ans.back()[1])
            {
                ans.push_back(arr[i]);
            }
            else
            {
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }

        return ans;
    }
};