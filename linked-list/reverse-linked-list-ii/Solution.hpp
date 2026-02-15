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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode **indirect = &head;
        for (int i = 1; i < left; ++i)
            indirect = &((*indirect)->next);
        *indirect = reverseFirstK(*indirect, right - left + 1);
        return head;
    }

    ListNode *reverseFirstK(ListNode *head, int k)
    {
        ListNode *node = head;
        ListNode *prev_node = nullptr;
        ListNode *next_node = nullptr;
        while (node && k--)
        {
            next_node = node->next;
            node->next = prev_node;

            prev_node = node;
            node = next_node;
        }
        head->next = next_node;
        return prev_node;
    }
};
