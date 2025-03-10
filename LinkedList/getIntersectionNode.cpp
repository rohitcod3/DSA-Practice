/**
 * @author : Rohit
 * @date   : 2024-03-04
 * @problem: 160. Intersection of Two Linked Lists
 * @link   : https://leetcode.com/problems/intersection-of-two-linked-lists/
 * @level  : Easy
 *
 * @description
 * Given the heads of two singly linked lists, return the node at which the two lists intersect.
 * If the two linked lists have no intersection, return null.
 *
 * Example:
 * Input: headA = [4,1,8,4,5], headB = [5,6,1,8,4,5]
 * Output: Node with value 8 (intersection point)
 *
 * @approach
 * - **Step 1**: Store all nodes of list A in a hash map.
 * - **Step 2**: Traverse list B and check if any node exists in the map.
 * - **Step 3**: If found, return the intersection node; otherwise, return null.
 *
 * @complexity
 * - Time Complexity: O(m + n) — m and n are the lengths of both linked lists.
 * - Space Complexity: O(m) — Due to the hash map storing nodes of list A.
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
        ListNode *temp = headA;
        unordered_map<ListNode *, int> mpp;
        while (temp != nullptr)
        {
            mpp[temp] = 1;
            temp = temp->next;
        }

        temp = headB;

        while (temp != nullptr)
        {
            if (mpp.find(temp) != mpp.end())
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};