/**
 * @author : Rohit
 * @date   : 2024-03-06
 * @problem: 19. Remove Nth Node From End of List
 * @link   : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * @level  : Medium
 *
 * @description
 * Given the head of a singly linked list, remove the n-th node from the end of the list and return its head.
 *
 * Example:
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 *
 * @approach
 * - Use the two-pointer technique (fast and slow):
 *    1. Move the fast pointer `n` steps ahead.
 *    2. If fast becomes NULL, it means the head node itself is to be removed.
 *    3. Move both fast and slow pointers together until fast reaches the end.
 *    4. The slow pointer will be just before the node to delete.
 *    5. Adjust pointers to remove the nth node and delete it.
 *
 * @complexity
 * Time Complexity: O(n) — Single pass through the list.
 * Space Complexity: O(1) — Constant extra space.
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        if (fast == nullptr)
            return head->next;

        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *delNode = slow->next;
        slow->next = slow->next->next;
        delete (delNode);
        return head;
    }
};