
/**
 * @author : Rohit
 * @date   : 2024-03-15
 * @problem: 92. Reverse Linked List II
 * @link   : https://leetcode.com/problems/reverse-linked-list-ii/
 * @level  : Medium
 *
 * @description
 * Given the head of a singly linked list and two integers left and right,
 * reverse the nodes from position left to right and return the modified list.
 *
 * Example:
 * Input: head = [1,2,3,4,5], left = 2, right = 4
 * Output: [1,4,3,2,5]
 *
 * @approach
 * - Use a dummy node to simplify edge cases when reversing from the head.
 * - Traverse to the left-th node using a `prev` pointer.
 * - Reverse the sublist from `left` to `right` using pointer manipulation.
 * - Maintain `prev` and `curr` pointers to perform in-place reversal.
 *
 * @complexity
 * - Time Complexity: O(n) since we traverse the list once and perform reversal in-place.
 * - Space Complexity: O(1) as the reversal is done without extra space.
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *dummy = new ListNode(0);

        dummy->next = head;

        ListNode *prev = dummy;

        for (int i = 1; i < left; i++)
        {
            prev = prev->next;
        }

        ListNode *curr = prev->next;

        for (int i = 1; i <= right - left; i++)
        {
            ListNode *temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
        }
        return dummy->next;
    }
};