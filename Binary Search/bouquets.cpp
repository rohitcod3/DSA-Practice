/**
 * @author : Rohit
 * @date   : 2025-01-03
 * @problem: Minimum Days to Make m Bouquets
 * @link   : https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
 * @level  : Medium
 *
 * @description
 * This function determines the minimum number of days required to make `m` bouquets, each with `k` flowers, from an array `bloomDay` representing the days it takes for each flower to bloom.
 *
 * If it is not possible to make `m` bouquets, the function returns `-1`.
 *
 * @approach
 * 1. **Binary Search on Days**:
 *    - Determine the range of days using the minimum and maximum bloom times in `bloomDay`.
 *    - Use binary search to find the minimum day where making `m` bouquets is possible.
 * 2. **Helper Function**:
 *    - The `possible` function checks if it is feasible to make `m` bouquets in a given number of days `day`.
 *    - It iterates through `bloomDay`:
 *      - Counts consecutive flowers blooming by day `day`.
 *      - When `k` consecutive flowers are counted, a bouquet is formed.
 *      - Resets the count for the next bouquet.
 * 3. **Optimization**:
 *    - If the required total flowers (`m * k`) exceed the size of `bloomDay`, return `-1` early.
 *    - Binary search narrows the range of possible days until the minimum day is found.
 *
 * @complexity
 * Time Complexity: O(n * log(max - min)), where `n` is the size of `bloomDay`.
 * - Binary search runs ( O(log(max - min)) ), where `max` and `min` are the maximum and minimum bloom times.
 * - The `possible` function iterates through `bloomDay` in O(n)  for each binary search iteration.
 * Space Complexity: O(1), as no additional data structures are used.
 *
 * @example
 * Input: bloomDay = [1, 10, 3, 10, 2], m = 3, k = 1
 * Output: 3
 * Explanation:
 * - We need 3 bouquets, each with 1 flower.
 * - On day 3, flowers blooming are: [1, 3, 2].
 * - Bouquets can be formed with flowers 1, 3, and 2.
 *
 * Input: bloomDay = [7, 7, 7, 7, 12, 7, 7], m = 2, k = 3
 * Output: 12
 * Explanation:
 * - We need 2 bouquets, each with 3 flowers.
 * - On day 12, flowers blooming are: [7, 7, 7, 7, 7, 7].
 * - Bouquets can be formed with the first 3 and the last 3 flowers.
 *
 * Input: bloomDay = [1, 10, 3, 10, 2], m = 3, k = 2
 * Output: -1
 * Explanation:
 * - We need 3 bouquets, each with 2 flowers.
 * - Total flowers needed = 6, but bloomDay has only 5 flowers.
 * - Return -1 as it is impossible to form the bouquets.
 */

class Solution
{
public:
    bool possible(vector<int> &arr, int day, int m, int k)
    {
        int cnt = 0;
        int noOfB = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= day)
            {
                cnt++;
            }
            else
            {
                noOfB += (cnt / k);
                cnt = 0;
            }
        }
        noOfB += (cnt / k);
        return noOfB >= m;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {

        long long val = m * 1LL * k * 1LL;
        if (val > bloomDay.size())
            return -1;
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        int low = mini, high = maxi;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (possible(bloomDay, mid, m, k))
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return low;
    }
};