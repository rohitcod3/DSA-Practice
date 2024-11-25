/**
 * @author : Rohit
 * @date   : 2024-11-21
 * @problem: Best Time to Buy and Sell Stock
 * @link   : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * @level  : Easy
 *
 * @description
 * This function calculates the maximum profit that can be achieved by buying and selling a stock once.
 * It traverses the array of prices and maintains the minimum price encountered so far (`mini`) and the maximum profit possible (`maxProfit`).
 *
 * @approach
 * 1. Initialize `mini` to the first day's price and `maxProfit` to 0.
 * 2. Traverse the prices from day 1 to the last day:
 *    - Calculate the potential profit for the current price (`prices[i] - mini`).
 *    - Update `maxProfit` if the potential profit is greater than the current `maxProfit`.
 *    - Update `mini` if the current price is lower than `mini`.
 * 3. Return `maxProfit` as the result.
 *
 * @complexity
 * Time Complexity: O(n) - Single traversal of the prices array.
 * Space Complexity: O(1) - No additional space used.
 *
 */

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = prices[0];
        int maxProfit = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++)
        {
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);
            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }
};