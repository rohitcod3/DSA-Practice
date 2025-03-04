/**
 * @author : Rohit
 * @date   : 2024-03-04
 * @problem: 328. Odd Even Linked List
 * @link   : https://leetcode.com/problems/odd-even-linked-list/
 * @level  : Medium
 *
 * @description
 * Reorder a linked list so that all nodes positioned at odd indices come before
 * nodes at even indices, preserving their original relative order.
 *
 * Example:
 * Input: head = [1,2,3,4,5]
 * Output: [1,3,5,2,4]
 *
 * Approach (Extra Space):
 * 1. Traverse and collect odd-indexed nodes.
 * 2. Traverse and collect even-indexed nodes.
 * 3. Overwrite the original linked list with the reordered values.
 *
 * Complexity:
 * Time Complexity: O(n)
 * Space Complexity: O(n) (due to the extra array)
 */

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *temp = head;
        vector<int> arr;
        while (temp != nullptr && temp->next != nullptr)
        {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp)
            arr.push_back(temp->val);

        temp = head->next;
        while (temp != nullptr && temp->next != nullptr)
        {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp)
            arr.push_back(temp->val);

        temp = head;
        int n = arr.size();
        int i = 0;
        while (temp != nullptr)
        {
            if (i <= n)
            {
                temp->val = arr[i];
                i++;
                temp = temp->next;
            }
        }
        return head;
    }
};