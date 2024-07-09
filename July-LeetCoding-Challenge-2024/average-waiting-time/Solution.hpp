// https://leetcode.com/problems/average-waiting-time/

#include <vector>

using namespace std;

class Solution
{
public:
    // Assumed FCFS
    double averageWaitingTime(vector<vector<int>>& customers)
    {
        int lastFinishedTime = 0;
        for (auto &pair : customers)
        {
            auto arrival = pair[0];
            auto time = pair[1];

            // if the chef is free when the customer arrives
            if (arrival >= lastFinishedTime)
            {
                lastFinishedTime = arrival + time;
            }
            else
            {
                pair[1] += lastFinishedTime - arrival; // add the time the chef was busy
                lastFinishedTime += time;
            }
        }

        if (customers.size() == 0)
            return 0;

        double sum = 0;
        for (auto &pair : customers)
        {
            sum += pair[1];
        }
        return sum / customers.size();
    }
};