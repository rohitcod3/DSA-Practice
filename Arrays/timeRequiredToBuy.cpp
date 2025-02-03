/**
 * @author : Rohit
 * @date   : 2025-02-03
 * @problem: Time Needed to Buy Tickets
 * @link   : https://leetcode.com/problems/time-needed-to-buy-tickets/
 * @level  : Easy
 *
 * @description
 * This function simulates the process of people buying tickets in a queue.
 * Given an array `tickets` where `tickets[i]` represents the number of tickets
 * a person at index `i` wants to buy, we determine how long it takes for the
 * person at index `k` to finish buying their tickets.
 *
 * @approach
 * 1. **Queue Simulation**:
 *    - Use a queue to store pairs of `{tickets[i], index}` representing the number
 *      of tickets needed and their original position.
 * 2. **Processing the Queue**:
 *    - Decrease the number of tickets for the person at the front of the queue.
 *    - If they still need tickets, move them to the back of the queue.
 *    - If a person finishes buying tickets and their index is `k`, return the time.
 *
 * @complexity
 * - Time Complexity: **O(n * max(tickets))** in the worst case, where `n` is the
 *   number of people and `max(tickets)` is the highest ticket count.
 * - Space Complexity: **O(n)** for storing queue elements.
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
        queue<pair<int, int>> q;
        int n = tickets.size();
        // add the array element and index of that element, in queue
        for (int i = 0; i < n; i++)
        {
            q.push({tickets[i], i});
        }

        int time = 0;
        while (!q.empty())
        {
            auto [cnt, idx] = q.front();
            q.pop();
            time++;
            cnt--;
            // if the cnt = 0 and the element who's cnt is 0, is the given k'th element, return the time taken get here
            if (cnt == 0)
            {
                if (idx == k)
                {
                    return time;
                }
            }
            else
            {
                q.push({cnt, idx});
            }
        }
        return time;
    }
};