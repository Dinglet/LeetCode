struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int len = length(head);
        int step = len - n;
        ListNode **indirect = &head;
        while (step--)
            indirect = &((*indirect)->next);
        (*indirect) = (*indirect)->next;
        return head;
    }

    int length(ListNode *head)
    {
        int count = 0;
        while (head)
        {
            ++count;
            head = head->next;
        }
        return count;
    }
};
