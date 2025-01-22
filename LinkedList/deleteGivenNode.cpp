/**
 * @author : Rohit
 * @date   : 2025-01-22
 * @problem: Delete Node in a Linked List
 * @link   : https://leetcode.com/problems/delete-node-in-a-linked-list/
 * @level  : Medium
 *
 * @description
 * This function deletes a given node (except the tail) from a singly linked list.
 * The node to be deleted is replaced by the next node, and the next node is removed from the list.
 * The input is guaranteed to be valid, i.e., the node to delete will never be the tail node.
 *
 * @approach
 * 1. **Copy the Value of the Next Node**:
 *    - The value of the next node is copied to the current node.
 * 2. **Adjust the Links**:
 *    - The `next` pointer of the current node is updated to point to the node after the next node.
 * 3. **Delete the Next Node**:
 *    - The next node (which is now redundant) is deleted to free memory.
 *
 * @complexity
 * Time Complexity: O(1), as only a constant number of operations are performed.
 * Space Complexity: O(1), as no additional space is used.
 *
 * @example
 * Input:
 * - Linked List: [4, 5, 1, 9]
 * - Node to delete: Node with value 5
 * Output:
 * - Linked List after deletion: [4, 1, 9]
 *
 * Input:
 * - Linked List: [4, 5, 1, 9]
 * - Node to delete: Node with value 1
 * Output:
 * - Linked List after deletion: [4, 5, 9]
 *
 * @note
 * - This approach does not truly "delete" the given node; instead, it modifies the given node to mimic the deletion.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        // we copy the value of the next node in the given node
        node->val = node->next->val;

        // after that we create a temp pointer, which points at the next node from the given node
        ListNode *temp = node->next;

        // the current node is linked with 2nd node ahead of the current node, the very next node to the     current node is skipped
        node->next = node->next->next;

        // the very next node is deleted after its value is copied into the given node, effectively deleting   the given node and maintaining the order
        delete temp;
    }
};