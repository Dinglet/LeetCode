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

        int length = 0;
        for (auto node = head; node; node = node->next)
            ++length;

        // reverse `n_tail` nodes
        const int n_tail = length / 2;
        ListNode *tail = head;
        for (int step = length - n_tail; step--;)
            tail = tail->next;
        tail = reverseList(tail);

        // insert reversed nodes into the list
        auto node = head; // 1
        for (int step = n_tail; step--;)
        {
            ListNode *next_node = node->next; // 2
            ListNode *next_tail = tail->next; // n-1

            node->next = tail;      // 1 -> n
            tail->next = next_node; // 1 -> n -> 2
            node = next_node;       // 2
            tail = next_tail;       // n-1
        }
        node->next = nullptr;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev_node = nullptr;
        while (head)
        {
            ListNode *next_node = head->next;
            head->next = prev_node;
            prev_node = head;
            head = next_node;
        }
        return prev_node;
    }
};
