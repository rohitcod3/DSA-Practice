/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
public:
    int countNodesinLoop(Node *head)
    {

        Node *slow = head;
        Node *fast = head;
        int count = 0;
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

                Node *starting = slow;
                do
                {
                    count++;
                    starting = starting->next;
                } while (starting != fast);
                return count;
            }
        }
        return 0;
    }
};