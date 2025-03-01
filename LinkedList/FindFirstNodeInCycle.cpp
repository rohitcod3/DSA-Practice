/**
 * @author : Rohit
 * @date   : 2025-03-01
 * @problem: Detect Cycle in a Linked List
 * @link   : https://leetcode.com/problems/linked-list-cycle/
 * @level  : Easy
 *
 * @description
 * This function detects whether a **cycle** exists in a **singly linked list**.
 * - A cycle occurs when a node’s `next` pointer connects back to a previous node.
 * - Uses **Floyd’s Cycle Detection Algorithm (Tortoise and Hare approach)**.
 *
 * @approach (Two Pointer Method)
 * 1. **Initialize Two Pointers**:
 *    - `slow` moves **one step** at a time.
 *    - `fast` moves **two steps** at a time.
 * 2. **Loop Until End or Cycle Detected**:
 *    - If `fast` reaches `NULL` (end of list), there is **no cycle**.
 *    - If `slow == fast`, a **cycle is detected**.
 * 3. **Return Result**:
 *    - `true` if a cycle is found.
 *    - `false` otherwise.
 *
 * @complexity
 * - Time Complexity: **O(N)**, where `N` is the number of nodes.
 *   - In the worst case, the fast pointer completes one full cycle before detection.
 * - Space Complexity: **O(1)**, as no extra space is used.
 *
 * @example
 * Input: head = [3,2,0,-4] (where `-4` connects back to `2`)
 * Output: true
 *
 * Input: head = [1,2] (where `2` points to `NULL`)
 * Output: false
 *
 * @note
 * - Floyd's algorithm is **efficient** and requires **constant space**.
 * - If a cycle exists, `slow` and `fast` will always meet inside the loop.
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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};