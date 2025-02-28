/**
 * @author : Rohit
 * @date   : 2025-02-26
 * @problem: Reverse a Linked List
 * @link   : https://leetcode.com/problems/reverse-linked-list/
 * @level  : Easy
 *
 * @description
 * This function reverses a given singly linked list using a stack-based approach.
 * - It does **not** modify the node pointers, only their values.
 *
 * @approach
 * 1. **Store Values in a Stack**:
 *    - Traverse the linked list and push all node values onto a stack.
 * 2. **Modify the List with Reversed Values**:
 *    - Traverse the list again, popping values from the stack and reassigning them to nodes.
 * 3. **Return Head**:
 *    - Since node positions remain unchanged, `head` still points to the first node.
 *
 * @complexity
 * - Time Complexity: **O(N)**, where `N` is the number of nodes.
 *   - Traversing the list twice: once to push values, once to update them.
 * - Space Complexity: **O(N)**, due to the stack storing `N` values.
 *
 * @example
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 * Explanation:
 * - Stack stores: [1,2,3,4,5]
 * - Rewriting list: head -> 5 → 4 → 3 → 2 → 1 → NULL
 *
 * @note
 * - This method is **not in-place** because it uses extra space.
 * - A more optimal solution reverses the `next` pointers iteratively (O(1) space).
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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        ListNode *temp = head;
        stack<int> st;

        while (temp != NULL)
        {
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;

        while (temp != NULL)
        {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};

// Recursive solution (optimal)

// T.C -> 0(N), S.C -> O(1)

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *newHead = reverseList(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
};