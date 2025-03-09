/**
 * @author : Rohit
 * @date   : 2024-03-09
 * @problem: 148. Sort List
 * @link   : https://leetcode.com/problems/sort-list/
 * @level  : Medium
 *
 * @description
 * Given the head of a linked list, return the list after sorting it in ascending order.
 *
 * Example:
 * Input: head = [4,2,1,3]
 * Output: [1,2,3,4]
 *
 * @approach
 * - **Base Case**: If the list is empty or has only one node, return the head.
 * - **Step 1**: Find the middle node of the linked list using the slow-fast pointer approach.
 * - **Step 2**: Split the list into two halves.
 * - **Step 3**: Recursively sort both halves using merge sort.
 * - **Step 4**: Merge the sorted halves using a helper function.
 *
 * @complexity
 * - Time Complexity: O(n log n) — T(n) = 2T(n/2) + O(n) (Merge Sort Recurrence)
 * - Space Complexity: O(log n) — Due to recursive stack calls.
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
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *mergeLinkedList(ListNode *list1, ListNode *list2)
    {
        ListNode *dummyNode = new ListNode(-1);
        ListNode *temp = dummyNode;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }
        if (list1)
            temp->next = list1;
        else
            temp->next = list2;
        return dummyNode->next;
    }

    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *middle = findMiddle(head);

        ListNode *left = head;
        ListNode *right = middle->next;
        middle->next = nullptr;

        left = sortList(left);
        right = sortList(right);

        return mergeLinkedList(left, right);
    }
};