// https://leetcode.com/problems/sort-list/

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
    ListNode *sortList(ListNode *head)
    {
        auto indirect = &head;
        while (*indirect)
        {
            auto min_indirect = indirect;
            for (auto i = &(*min_indirect)->next; *i; i = &((*i)->next))
            {
                if ((*i)->val < (*min_indirect)->val)
                    min_indirect = i;
            }
            if (*indirect != *min_indirect)
            {
                auto node = *indirect;
                auto min_node = *min_indirect;
                *min_indirect = min_node->next;
                *indirect = min_node;
                min_node->next = node;
            }
            indirect = &((*indirect)->next);
        }
        return head;
    }
};