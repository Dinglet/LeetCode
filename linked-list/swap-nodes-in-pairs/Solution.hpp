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
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next) // length is 0 or 1
            return head;

        ListNode **indirect = &head;
        while (*indirect && (*indirect)->next)
        {
            ListNode *nodes[2] = {*indirect, (*indirect)->next};
            nodes[0]->next = nodes[1]->next;
            nodes[1]->next = nodes[0];
            *indirect = nodes[1];

            indirect = &nodes[0]->next;
        }

        return head;
    }
};
