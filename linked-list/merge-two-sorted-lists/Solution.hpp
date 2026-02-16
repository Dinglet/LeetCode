// https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = nullptr;
        ListNode **indirect = &head;
        while (list1 && list2)
        {
            if (list2->val < list1->val)
            {
                *indirect = list2;
                list2 = list2->next;
            }
            else
            {
                *indirect = list1;
                list1 = list1->next;
            }
            indirect = &((*indirect)->next);
        }
        // link the rest
        *indirect = list1 ? list1 : list2;

        return head;
    }
};