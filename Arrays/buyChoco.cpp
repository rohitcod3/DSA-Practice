/**
 * @author : Rohit
 * @date   : 2024-12-01
 * @problem: Buy Two Chocolates
 * @link   : (https://leetcode.com/problems/buy-two-chocolates/)
 * @level  : Easy
 *
 * @description
 * This function determines how much money remains after buying two chocolates with the lowest prices,
 * provided you have sufficient money to buy them. If it's not possible to buy two chocolates,
 * the entire amount of money is returned.
 *
 * @approach
 * 1. Traverse the array to find the two smallest prices (`minPrice` and `secMinPrice`).
 * 2. Check if the sum of the two smallest prices exceeds the available money:
 *    - If yes, return the total money as no chocolates can be bought.
 *    - If no, return the remaining money after buying the two chocolates.
 *
 * @complexity
 * Time Complexity: O(n) - Single traversal to find the two smallest prices.
 * Space Complexity: O(1) - No additional space is used.
 *
 */

class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        int minPrice = INT_MAX;
        int secMinPrice = INT_MAX;

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minPrice)
            {
                secMinPrice = minPrice;
                minPrice = prices[i];
            }
            else if (prices[i] < secMinPrice)
            {
                secMinPrice = prices[i];
            }
        }

        if (minPrice + secMinPrice > money)
        {
            return money;
        }

        return money - (minPrice + secMinPrice);
    }
};
