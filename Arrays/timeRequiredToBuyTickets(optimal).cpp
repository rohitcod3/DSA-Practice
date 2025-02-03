
/**
 * @author : Rohit
 * @date   : 2025-02-04
 * @problem: Time Needed to Buy Tickets
 * @link   : https://leetcode.com/problems/time-needed-to-buy-tickets/
 * @level  : Easy
 *
 * @description
 * This function calculates the total time required for the person at index `k`
 * to buy all their tickets from a queue where every person at index `i` needs
 * `tickets[i]` tickets. Each person can buy one ticket per iteration in order.
 *
 * @approach
 * 1. **Iterate Over the Array**:
 *    - Traverse from left to right and calculate the total time needed.
 * 2. **Conditions**:
 *    - If `i <= k`: The person at index `i` buys tickets normally.
 *    - If `i > k`: The person can only buy `tickets[k] - 1` tickets because the person
 *      at `k` will complete their purchase before them.
 *
 * @complexity
 * - Time Complexity: **O(n)**, since we traverse the list once.
 * - Space Complexity: **O(1)**, since no extra space is used.
 *
 * @example
 * Input: tickets = [2, 3, 2], k = 2
 * Output: 6
 * Explanation:
 * - Person at index 0 buys 1 ticket → [1, 3, 2]
 * - Person at index 1 buys 1 ticket → [1, 2, 2]
 * - Person at index 2 buys 1 ticket → [1, 2, 1]
 * - Person at index 0 buys 1 ticket → [0, 2, 1]
 * - Person at index 1 buys 1 ticket → [0, 1, 1]
 * - Person at index 2 buys 1 ticket → [0, 1, 0] (stops here as `k=2`)
 */

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int n = tickets.size();
        int time = 0;

        for (int i = 0; i < n; i++)
        {
            if (tickets[k] == 0)
                return time;

            if (i <= k)
            {
                time += min(tickets[i], tickets[k]);
            }
            if (i > k)
            {
                time += min(tickets[k] - 1, tickets[i]);
            }
        }
        return time;
    }
};