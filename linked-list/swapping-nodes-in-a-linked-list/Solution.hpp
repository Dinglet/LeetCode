#include <algorithm>

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
    ListNode *swapNodes(ListNode *head, int k)
    {
        int len = length(head);
        if (k - 1 == len - k) // k is the middle
            return head;
        k = min(k, len - k + 1);

        ListNode **indirects[2] = {&head, &head};
        for (int step = k - 1; step--;)
            indirects[0] = &((*indirects[0])->next);
        for (int step = len - k; step--;)
            indirects[1] = &((*indirects[1])->next);

        ListNode *nodes[2] = {*indirects[0], *indirects[1]};
        if (nodes[0]->next == nodes[1])
        {
            // swap adjacent nodes
            nodes[0]->next = nodes[1]->next;
            nodes[1]->next = nodes[0];
            *indirects[0] = nodes[1];
        }
        else
        {
            // two nodes are not adjacent
            swap(nodes[0]->next, nodes[1]->next);
            swap(*indirects[0], *indirects[1]);
        }

        return head;
    }

    int length(ListNode *head)
    {
        int count = 0;
        while (head)
        {
            ++count;
            head = head->next;
        }
        return count;
    }
};
