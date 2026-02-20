// https://leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        do
        {
            if (!fast || !fast->next)
                return nullptr;
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);
        // Two pointers meet here, but the cycle may begin before.
        //
        // It takes `s` steps to go from `head` to `slow`, and
        // it takes `2*s` steps to go from `head` to `fast`.
        // Since `slow == fast`, the difference `s` (`2*s - s`) is a multiple of the length of the cycle.
        //
        // Suppose that it takes `m` steps to go from `head` to the first node which will be visited later.
        // We can find such node by taking steps from `head` and `fast` (or `slow`) with 1 step at a time.
        // Two pointers will meet after both take `m` steps.

        slow = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
