/**
 * @author : Rohit
 * @date   : 2024-03-03
 * @problem: 234. Palindrome Linked List
 * @link   : https://leetcode.com/problems/palindrome-linked-list/
 * @level  : Easy
 *
 * @description
 * This problem checks whether a singly linked list is a palindrome.
 * A palindrome is a sequence that reads the same backward as forward.
 *
 * Approach (Optimal - O(1) Space):
 * 1. Use two pointers (`slow` and `fast`) to find the middle of the linked list.
 *    - `slow` moves one step at a time.
 *    - `fast` moves two steps at a time.
 *    - When `fast` reaches the end, `slow` is at the middle.
 *
 * 2. Reverse the second half of the linked list starting from `slow->next`.
 *
 * 3. Compare the first half and the reversed second half:
 *    - Move both pointers and compare values.
 *    - If any mismatch occurs, it's not a palindrome.
 *
 * 4. Restore the list by reversing the second half again to maintain the original structure.
 *
 * 5. Return `true` if all corresponding nodes match, else `false`.
 *
 * Example:
 * Input: head = [1,2,2,1]
 * Output: true
 *
 * Input: head = [1,2]
 * Output: false
 *
 * Time Complexity: O(n)
 *  - Finding the middle takes O(n).
 *  - Reversing half the list takes O(n).
 *  - Comparing takes O(n).
 *
 * Space Complexity: O(1)
 *  - Only pointers are used for traversal and reversal.
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
    ListNode *reverse(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *newHead = reverse(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }

    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *newHead = reverse(slow->next);
        ListNode *first = head;
        ListNode *second = newHead;

        while (second != nullptr)
        {
            if (first->val != second->val)
            {
                reverse(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverse(newHead);
        return true;
    }
};