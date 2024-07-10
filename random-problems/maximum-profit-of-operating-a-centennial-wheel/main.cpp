#include <iostream>

#include "Solution.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> customers = {10,9,6};
    int boardingCost = 6;
    int runningCost = 4;

    cout << solution.minOperationsMaxProfit(customers, boardingCost, runningCost) << endl;
    return 0;
}
