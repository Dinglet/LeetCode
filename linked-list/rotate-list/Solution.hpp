// https://leetcode.com/problems/rotate-list/

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (k <= 0)
            return head;

        int length = 0;
        ListNode **indirect = &head;
        while (*indirect)
        {
            ++length;
            indirect = &((*indirect)->next);
        }
        // indirect points to the first nullptr

        if (length == 0)
            return head;
        k %= length;
        if (k == 0)
            return head;

        *indirect = head; // make a circle
        indirect = &head;
        int step = length - k;
        while (step--)
        {
            indirect = &((*indirect)->next);
        }
        ListNode *new_head = *indirect;
        *indirect = nullptr;
        return new_head;
    }
};
