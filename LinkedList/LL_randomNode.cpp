/**
 * @author : Rohit
 * @date   : 2024-03-14
 * @problem: 382. Linked List Random Node
 * @link   : https://leetcode.com/problems/linked-list-random-node/
 * @level  : Medium
 *
 * @description
 * Given a singly linked list, implement a class that allows retrieving a random node's value
 * with equal probability.
 *
 * Example:
 * Input: [1, 2, 3]
 * Output: Randomly returns 1, 2, or 3 with equal probability.
 *
 * @approach
 * - Use **Reservoir Sampling** to select a node with uniform probability.
 * - Traverse the linked list while maintaining a counter.
 * - At each step, replace the current result with probability **1/count**.
 *
 * @complexity
 * - Time Complexity: O(n) for `getRandom()` since it requires a full traversal.
 * - Space Complexity: O(1) since no extra storage is used.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *Head;
    Solution(ListNode *head)
    {
        Head = head;
    }

    int getRandom()
    {
        int count = 1;
        int result = 0;

        ListNode *temp = Head;

        while (temp != nullptr)
        {
            if (rand() % count < 1.0 / count)
            {
                result = temp->val;
            }
            count++;
            temp = temp->next;
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */