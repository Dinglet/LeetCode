// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode** indirect = &head;
        while ((*indirect)->next) {
            if ((*indirect)->val == (*indirect)->next->val)
                (*indirect)->next = (*indirect)->next->next;
            else
                indirect = &(*indirect)->next;
        }
        return head;
    }
};
