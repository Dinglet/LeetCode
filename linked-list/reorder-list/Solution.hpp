// https://leetcode.com/problems/reorder-list/submissions/

#include <stack>

using namespace std;

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
    void reorderList(ListNode *head)
    {
        if (!head)
            return;
        stack<ListNode *> nodes;
        for (auto node = head; node; node = node->next)
        {
            nodes.push(node);
        }
        int length = nodes.size();
        int t = length / 2;

        auto node = head; // 1
        while (t--)
        {
            ListNode *next_node = node->next;  // 2
            ListNode *back_node = nodes.top(); // n
            nodes.pop();

            node->next = back_node;      // 1 -> n
            back_node->next = next_node; // 1 -> n -> 2
            node = next_node;            // 2
        }
        node->next = nullptr;
    }
};
