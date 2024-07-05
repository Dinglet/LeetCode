#include <iostream>
#include <vector>

#include "Solution.hpp"

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> distances;

    printf("Test case 2\n");
    // 5,3,1,2,5,1,2
    printf("5,3,1,2,5,1,2\n");
    ListNode* head = new ListNode(5);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(2);
    distances = solution.nodesBetweenCriticalPoints(head);
    printf("Minimum distance: %d\n", distances[0]);
    printf("Maximum distance: %d\n", distances[1]);
    printf("\n");

    return 0;
}
