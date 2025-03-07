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
    ListNode *deleteMiddle(ListNode *head)
    {
        ListNode *temp = head;
        int cnt = 0;
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        while (temp != nullptr)
        {
            cnt++;
            temp = temp->next;
        }
        temp = head;
        int res = (cnt / 2) - 1;
        while (res--)
        {
            temp = temp->next;
        }
        ListNode *delNode = temp->next;

        if (temp != nullptr && temp->next != nullptr)
        {
            temp->next = temp->next->next;
            delete (delNode);
        }
        return head;
    }
};