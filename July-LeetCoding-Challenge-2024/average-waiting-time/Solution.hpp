// https://leetcode.com/problems/average-waiting-time/

#include <vector>

using namespace std;

class Solution
{
public:
    // Assumed FCFS
    double averageWaitingTime(vector<vector<int>>& customers)
    {
        if (customers.size() == 0)
            return 0;

        double sum = 0;
        int lastFinishedTime = 0;
        for (const auto &pair : customers)
        {
            const auto &arrival = pair[0];
            const auto &time = pair[1];

            // if the chef is free when the customer arrives
            if (arrival >= lastFinishedTime)
            {
                sum += time; // add the time needed to prepare the order
                lastFinishedTime = arrival + time;
            }
            else
            {
                sum += lastFinishedTime - arrival + time; // add the cook busy time + the time needed to prepare the order
                lastFinishedTime += time;
            }
        }

        return sum / customers.size();
    }
};