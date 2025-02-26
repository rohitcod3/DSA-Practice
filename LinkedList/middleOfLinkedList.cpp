/**
 * @author : Rohit
 * @date   : 2025-02-25
 * @problem: Middle of the Linked List
 * @link   : https://leetcode.com/problems/middle-of-the-linked-list/
 * @level  : Easy
 *
 * @description
 * Given the head of a singly linked list, return the middle node.
 * - If there are two middle nodes, return the second middle node.
 *
 * @appro ach
 * **Two-Pass Approach (Counting Nodes)**
 * 1. **First Pass**:
 *    - Traverse the list to count the total number of nodes (`cnt`).
 * 2. **Second Pass**:
 *    - Find the middle index: `mid = (cnt / 2) + 1`.
 *    - Traverse again and stop at the `mid`th node.
 *    - Return the middle node.
 *
 * @complexity
 * **Time Complexity**: O(n) → Two passes through the linked list.
 * **Space Complexity**: O(1) → Only integer variables used for counting.
 *
 * @example
 * **Input**: head = [1,2,3,4,5]
 * **Output**: [3,4,5]
 * **Explanation**: The middle node is `3`.
 *
 * **Input**: head = [1,2,3,4,5,6]
 * **Output**: [4,5,6]
 * **Explanation**: Since there are two middle nodes, return the second middle node `4`.
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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *temp = head;
        int cnt = 0;
        while (temp != nullptr)
        {
            cnt++;
            temp = temp->next;
        }
        int result = (cnt / 2) + 1;
        temp = head;
        while (temp != nullptr)
        {
            result--;
            if (result == 0)
                break;
            temp = temp->next;
        }
        return temp;
    }
};

// Optimized Sol
//  Using slow and fast pointers
//@approach
//* **Two-Pointer (Fast & Slow) Approach**
//  * 1. **Use Two Pointers**:
//  *    - `slow` moves one step at a time.
//  *    - `fast` moves two steps at a time.
//  * 2. **When `fast` reaches the end**:
//  *    - `slow` is at the middle node.
//*    - Return `slow` as the middle node.
//  @complexity
//  * **Time Complexity**: O(n) → Single pass through the linked list.
//  * **Space Complexity**: O(1) → No extra space used.
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};