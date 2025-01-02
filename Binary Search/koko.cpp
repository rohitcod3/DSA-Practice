/**
 * @author : Rohit
 * @date   : 2025-01-02
 * @problem: Koko Eating Bananas
 * @link   : https://leetcode.com/problems/koko-eating-bananas/
 * @level  : Medium
 *
 * @description
 * This function determines the minimum eating speed `k` that allows Koko to finish eating all banana piles within `h` hours.
 *
 * Each pile has a specific number of bananas, and Koko can only eat bananas from one pile at a time.
 * If she eats at speed `k`, it takes ⌈pile / k⌉ hours to eat the pile.
 *
 * @approach
 * 1. **Binary Search**:
 *    - Use `low = 1` and `high = max(piles)` to define the search range for `k`.
 *    - Calculate `mid = low + (high - low) / 2`.
 * 2. **Simulate Eating Time**:
 *    - Iterate over all piles and calculate the total hours required to eat the bananas at speed `mid`:
 *      - For each pile, compute ⌈pile / mid⌉ using integer arithmetic as `(pile + mid - 1) / mid`.
 *    - If the total hours ≤ h, reduce the speed by setting `high = mid`.
 *    - Otherwise, increase the speed by setting `low = mid + 1`.
 * 3. **Return Result**:
 *    - The `low` variable will hold the minimum speed `k` that satisfies the condition.
 *
 * @complexity
 * Time Complexity: O(n * log m), where `n` is the number of piles and `m` is the largest pile size.
 * - Binary search iterates log m times.
 * - Each iteration calculates the total hours in O(n).
 * Space Complexity: O(1), as no additional data structures are used.
 *
 * @example
 * Input: piles = [3, 6, 7, 11], h = 8
 * Output: 4
 * Explanation:
 * - For eating speed `k = 4`:
 *   - Pile 3: ⌈3 / 4⌉ = 1 hour
 *   - Pile 6: ⌈6 / 4⌉ = 2 hours
 *   - Pile 7: ⌈7 / 4⌉ = 2 hours
 *   - Pile 11: ⌈11 / 4⌉ = 3 hours
 * - Total hours: 1 + 2 + 2 + 3 = 8 hours
 *
 * Input: piles = [30, 11, 23, 4, 20], h = 5
 * Output: 30
 * Explanation:
 * - For eating speed `k = 30`:
 *   - Pile 30: ⌈30 / 30⌉ = 1 hour
 *   - Pile 11: ⌈11 / 30⌉ = 1 hour
 *   - Pile 23: ⌈23 / 30⌉ = 1 hour
 *   - Pile 4: ⌈4 / 30⌉ = 1 hour
 *   - Pile 20: ⌈20 / 30⌉ = 1 hour
 * - Total hours: 1 + 1 + 1 + 1 + 1 = 5 hours
 */

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        while (low < high)
        {
            int mid = low + (high - low) / 2;
            long long hours = 0;

            for (int pile : piles)
            {
                hours += (pile + mid - 1) / mid;
            }

            if (hours <= h)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};