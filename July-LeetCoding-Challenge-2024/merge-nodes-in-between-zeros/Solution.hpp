// https://leetcode.com/problems/merge-nodes-in-between-zeros/

// Definition for singly-linked list.
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
    ListNode* mergeNodes(ListNode* head)
    {
        ListNode* current = head;
        ListNode* prev = nullptr;

        while (current->next) // next node exists
        {
            if (current->next->val != 0)
            {
                // merge with the non-zero node
                current->val += current->next->val;
                current->next = current->next->next;
            }
            else
            {
                prev = current;
                current = current->next; // next zero node
            }
        }

        if (prev)
        {
            prev->next = nullptr;
        }

        return head;
    }
};