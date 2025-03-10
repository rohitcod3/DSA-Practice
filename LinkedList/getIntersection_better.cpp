/**
 * @author : Rohit
 * @date   : 2025-03-04
 * @problem: 160. Intersection of Two Linked Lists
 * @link   : https://leetcode.com/problems/intersection-of-two-linked-lists/
 * @level  : Easy
 *
 * @description
 * Given the heads of two singly linked lists, return the node where the two lists intersect.
 * If the two linked lists have no intersection at all, return nullptr.
 *
 * Example:
 * Input: headA = [4,1,8,4,5], headB = [5,6,1,8,4,5]
 * Output: Reference to the node with value 8
 *
 * @approach
 * - **Step 1**: Calculate the length of both linked lists.
 * - **Step 2**: Move the pointer of the longer list forward by the difference in lengths.
 * - **Step 3**: Traverse both lists together until a common node is found.
 * - **Step 4**: If no intersection is found, return nullptr.
 *
 * @complexity
 * - Time Complexity: O(N + M) — Traverses both lists once.
 * - Space Complexity: O(1) — Uses only a few extra pointers.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr && headA->next == nullptr)
            return headA;
        if (headB == nullptr && headB->next == nullptr)
            return headB;
        int n1 = 0; // 5
        int n2 = 0; // 7

        ListNode *temp = headA;
        ListNode *t = nullptr;
        while (temp != nullptr)
        {
            n1++;
            temp = temp->next;
        }
        temp = headB;

        while (temp != nullptr)
        {
            n2++;
            temp = temp->next;
        }

        int d = abs(n2 - n1); // 2

        if (n1 > n2)
        {
            temp = headA;
            while (d--)
            {
                temp = temp->next;
            }
            t = headB;
        }
        else
        {
            temp = headB;
            while (d--)
            {
                temp = temp->next;
            }
            t = headA;
        }

        while (t != temp || t != nullptr)
        {
            if (t == temp)
                return temp;
            t = t->next;
            temp = temp->next;
        }

        return nullptr;
    }
};