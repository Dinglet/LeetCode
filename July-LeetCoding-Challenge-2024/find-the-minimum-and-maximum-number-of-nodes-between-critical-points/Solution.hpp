// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head)
    {
        vector<int> distances = {-1, -1}; // minDistance, maxDistance

        if (!head || !head->next) // if there is no node or only one node,
            return distances;

        ListNode *current = head;
        bool bIncreasing = false;
        bool bDecreasing = false;
        // Initialize the flags according to the first two nodes
        if (current->val < current->next->val)
            bIncreasing = true;
        else if (current->val > current->next->val)
            bDecreasing = true;

        // int pre = current->val;
        // Find the first critical point
        for (current = head->next; current->next; /*pre = current->val,*/ current = current->next)
        {
            // printf("%d (%d %d)", pre, current->val, current->next->val);

            if (current->val == current->next->val)
            {
                // printf(" (non-increasing and non-decreasing)\n");
                bIncreasing = false;
                bDecreasing = false;
            }
            else if (current->val < current->next->val)
            {
                // printf(" (increasing)\n");
                bIncreasing = true;
                if (bDecreasing)
                {
                    bDecreasing = false;
                    break;
                }
            }
            else // (current->val > current->next->val)
            {
                // printf(" (decreasing)\n");
                bDecreasing = true;
                if (bIncreasing)
                {
                    bIncreasing = false;
                    break;
                }
            }
        }

        if (!current->next) // if there is no critical point,
            return distances;

        distances[0] = INT_MAX;
        distances[1] = 0;
        int count = 0;
        for (; current->next; current = current->next)
        {
            if (current->val == current->next->val)
            {
                bIncreasing = false;
                bDecreasing = false;
            }
            else if (current->val < current->next->val)
            {
                bIncreasing = true;
                if (bDecreasing)
                {
                    bDecreasing = false;

                    distances[0] = min(distances[0], count);
                    distances[1] += count;
                    count = 0;
                }
            }
            else // (current->val > current->next->val)
            {
                bDecreasing = true;
                if (bIncreasing)
                {
                    bIncreasing = false;

                    distances[0] = min(distances[0], count);
                    distances[1] += count;
                    count = 0;
                }
            }
            count++;
        }

        if (distances[0] == INT_MAX)
            distances[0] = distances[1] = -1;

        return distances;
    }
};