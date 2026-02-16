#include <iostream>
#include <vector>

#include "Solution.hpp"

using namespace std;

void printList(ListNode *head)
{
    if (!head)
    {
        cout << "[]" << endl;
        return;
    }

    cout << "[" << head->val;
    head = head->next;
    while (head)
    {
        cout << "," << head->val;
        head = head->next;
    }
    cout << "]" << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{4, 2, 1, 3};
    vector<ListNode *> nodes;
    for (int n : nums)
        nodes.emplace_back(new ListNode{n});
    for (int i = 0; i + 1 < nodes.size(); ++i)
        nodes[i]->next = nodes[i + 1];
    ListNode *head = nodes.front();

    Solution s;
    printList(head);
    ListNode *sorted = s.sortList(head);
    printList(sorted);

    for (auto node : nodes)
        delete node;
    return 0;
}
