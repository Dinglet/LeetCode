// https://leetcode.com/problems/sort-list/
//
// O(n log n) time and O(1) memory
// https://leetcode.com/problems/sort-list/solutions/46712/bottom-to-upnot-recurring-with-o1-space-anpva

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
        int length = 0;
        for (auto node = head; node; node = node->next)
            ++length;

        for (int step = 1; step < length; step <<= 1)
        {
            auto indirect = &head;
            auto next = head;
            while (next)
            {
                ListNode *first = next;
                ListNode *second = split(first, step);
                next = split(second, step);
                indirect = merge(indirect, first, second);
                *indirect = next;
            }
        }
        return head;
    }

    // step > 0
    ListNode *split(ListNode *head, int step)
    {
        auto indirect = &head;
        while (step-- && *indirect)
            indirect = &((*indirect)->next);
        auto second = *indirect;
        *indirect = nullptr;
        return second;
    }

    ListNode **merge(ListNode **indirect, ListNode *first, ListNode *second)
    {
        while (first && second)
        {
            if (second->val < first->val)
            {
                *indirect = second;
                second = second->next;
            }
            else
            {
                *indirect = first;
                first = first->next;
            }
            indirect = &((*indirect)->next);
        }
        *indirect = first ? first : second;

        while (*indirect)
            indirect = &((*indirect)->next);
        return indirect;
    }
};
