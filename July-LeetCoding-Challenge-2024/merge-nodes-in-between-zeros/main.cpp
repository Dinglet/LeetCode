#include <iostream>

#include "Solution.hpp"

int main(int argc, char const *argv[])
{
    Solution solution;

    // Test case 1
    // 0,3,1,0,4,5,2,0
    ListNode* head = new ListNode(0);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next->next = new ListNode(0);

    ListNode* result = solution.mergeNodes(head);
    ListNode* current = result;
    while (current != nullptr)
    {
        printf("%d ", current->val);
        current = current->next;
    }

    current = head;
    while (current != nullptr)
    {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
