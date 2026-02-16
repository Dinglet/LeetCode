// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode **indirect = &head;
        while (*indirect)
        {
            if ((*indirect)->next && (*indirect)->val == (*indirect)->next->val)
            {
                int duplicate_val = (*indirect)->val;
                while (*indirect && duplicate_val == (*indirect)->val)
                    (*indirect) = (*indirect)->next;
            }
            else
            {
                indirect = &(*indirect)->next;
            }
        }
        return head;
    }
};
