/**
 * @author : Rohit
 * @date   : 2024-03-02
 * @problem: 234. Palindrome Linked List
 * @link   : https://leetcode.com/problems/palindrome-linked-list/
 * @level  : Easy
 *
 * @description
 * This problem checks whether a singly linked list is a palindrome.
 * A palindrome is a sequence that reads the same backward as forward.
 *
 * Approach (Using Stack):
 * 1. Traverse the linked list and push all node values into a stack.
 * 2. Traverse the list again from the head:
 *    - For each node, compare its value with the top value of the stack.
 *    - If they are equal, pop the stack and move to the next node.
 *    - If they are not equal, return false (it's not a palindrome).
 * 3. If the entire list is traversed without mismatch, return true.
 *
 * Example:
 * Input: head = [1,2,2,1]
 * Output: true
 *
 * Input: head = [1,2]
 * Output: false
 *
 * Time Complexity: O(n)
 *  - First traversal to fill the stack takes O(n).
 *  - Second traversal to compare takes O(n).
 *
 * Space Complexity: O(n)
 *  - Stack stores n elements from the linked list.
 */

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *temp = head;
        stack<int> st;

        while (temp != nullptr)
        {
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;

        while (temp != nullptr)
        {
            if (temp->val == st.top())
            {
                st.pop();
                temp = temp->next;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
