/**
 * @author : Rohit
 * @date   : 2024-03-05
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
 * 1. Count the total number of nodes in the list.
 * 2. If the node to remove is the head (n == total count), move the head pointer to the next node.
 * 3. Otherwise:
 *    - Traverse to the (count - n - 1)th node (the node before the one we need to remove).
 *    - Update its next pointer to skip the target node.
 *    - Delete the target node to free memory.
 *
 * @complexity
 * Time Complexity: O(n) — One pass to count nodes, another to remove the nth node.
 * Space Complexity: O(1) — Constant extra space.
 */

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        int cnt = 0;
        while (temp != nullptr)
        {
            cnt++;
            temp = temp->next;
        }

        if (n == cnt)
        {
            ListNode *newHead = head->next;
            delete (head);
            return newHead;
        }
        temp = head;
        int res = cnt - n - 1;
        while (res != 0)
        {
            res--;
            temp = temp->next;
        }
        if (temp != nullptr && temp->next != nullptr)
        {
            ListNode *deleteNode = temp->next;
            temp->next = temp->next->next;
            delete deleteNode;
        }
        return head;
    }
};