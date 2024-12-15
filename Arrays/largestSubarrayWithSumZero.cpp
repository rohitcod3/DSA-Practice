/**
 * @author : Rohit
 * @date   : 2024-12-15
 * @problem: Largest Subarray with Sum Zero
 * @link   : https://www.geeksforgeeks.org/find-the-largest-subarray-with-0-sum/
 * @level  : Medium
 *
 * @description
 * This function finds the length of the largest subarray in the given array `arr` with a sum of zero.
 * It uses a hashmap (unordered_map) to efficiently track the cumulative sum and its first occurrence.
 *
 * How It Works:
 * - **Map Tracks Cumulative Sum**:
 *   - The unordered_map stores the first occurrence of each cumulative sum along with its index.
 * - **Check Conditions**:
 *   - If `sum == 0`, the entire subarray from index 0 to `i` has a sum of zero.
 *   - If the sum has been seen before, the subarray between the previous index (from the map) and the current index has a sum of zero.
 * - **Update Maximum Length**:
 *   - Update `maxi` if a longer subarray is found.
 *
 * @complexity
 * Time Complexity: O(n), where `n` is the size of the array. Each element is processed once, and hashmap operations take O(1) on average.
 * Space Complexity: O(n), for storing the cumulative sums in the hashmap.
 */

int largestSubarrayWithSumZero(vector<int> arr, int n)
{
    unordered_map<int, int> mpp;
    int maxi = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxi = i + 1;
        }

        else if (mpp.find(sum) != mpp.end())
        {
            int len = i - mpp[sum];
            maxi = max(maxi, len);
        }
        else
        {
            mpp[sum] = i;
        }
    }

    return maxi;
}
