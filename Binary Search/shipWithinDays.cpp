/**
 * @author : Rohit
 * @date   : 2025-01-06
 * @problem: Capacity to Ship Packages Within D Days
 * @link   : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
 * @level  : Medium
 *
 * @description
 * This function determines the minimum capacity required for a ship to deliver all packages within `days` days.
 *
 * Each package has a specific weight, and the ship can only carry a limited weight per day.
 * The goal is to minimize the ship's capacity while ensuring that all packages are delivered within the given `days`.
 *
 * @approach
 * 1. **Binary Search on Capacity**:
 *    - The minimum capacity (`low`) is the maximum weight of a single package.
 *    - The maximum capacity (`high`) is the total weight of all packages.
 *    - Perform binary search to find the minimum capacity:
 *      - Calculate `mid = (low + high) / 2` as the current capacity.
 *      - Use the helper function `findDays` to determine the number of days required with this capacity.
 *      - If the number of days is within `days`, reduce the capacity by setting `high = mid - 1`.
 *      - Otherwise, increase the capacity by setting `low = mid + 1`.
 * 2. **Helper Function `findDays`**:
 *    - Simulates the process of shipping packages with a given capacity `cap`.
 *    - Returns the number of days required to ship all packages without exceeding the capacity on any day.
 *
 * @complexity
 * Time Complexity: O(n * log(sum - max)), where `n` is the number of packages, `sum` is the total weight of packages, and `max` is the maximum package weight.
 * - Binary search runs \( O(\log(sum - max)) \).
 * - For each capacity, the `findDays` function iterates through the array in \( O(n) \).
 * Space Complexity: O(1), as no additional data structures are used.
 *
 * @example
 * Input: weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], days = 5
 * Output: 15
 * Explanation:
 * - The minimum capacity to ship the packages within 5 days is 15.
 *
 * Input: weights = [3, 2, 2, 4, 1, 4], days = 3
 * Output: 6
 * Explanation:
 * - The minimum capacity to ship the packages within 3 days is 6.
 */

class Solution
{
public:
    int findDays(vector<int> &weights, int cap)
    {
        int days = 1, load = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            if (weights[i] + load > cap)
            {
                days += 1;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int numberOfDays = findDays(weights, mid);
            if (numberOfDays <= days)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};