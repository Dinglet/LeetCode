// https://leetcode.com/problems/partition-list/

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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode **slow_indirect = &head;
        while (*slow_indirect && (*slow_indirect)->val < x)
        {
            slow_indirect = &(*slow_indirect)->next;
        }
        // (*slow_indirect) points to the first node with val >= x

        // traverse remaining nodes
        ListNode **fast_indirect = slow_indirect;
        while (*fast_indirect)
        {
            // ListNode* node = *fast_indirect;
            ListNode *next_node = (*fast_indirect)->next;
            if ((*fast_indirect)->val < x)
            {
                // node points to the node with val < x
                // make node->next point to (*slow_indirect)
                (*fast_indirect)->next = *slow_indirect;
                // make (*slow_indirect) point to node
                *slow_indirect = *fast_indirect;
                // make (*fast_indirect) point to the next node
                *fast_indirect = next_node;

                slow_indirect = &((*slow_indirect)->next);
            }
            else
            {
                fast_indirect = &((*fast_indirect)->next);
            }
        }
        return head;
    }
};
