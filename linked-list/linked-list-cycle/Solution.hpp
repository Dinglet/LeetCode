// https://leetcode.com/problems/linked-list-cycle/

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
    bool hasCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        do
        {
            if (!fast || !fast->next)
                return false;
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);
        return true;
    }
};
