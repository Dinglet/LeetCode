#include <iostream>
#include <vector>

#include "Solution.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Solution solution;

    // Example 1
    vector<vector<int>> customers1 = {{1, 2}, {2, 5}, {4, 3}};
    for (auto &pair : customers1)
    {
        printf("[%d, %d] ", pair[0], pair[1]);
    }
    printf("\n");
    cout << solution.averageWaitingTime(customers1) << endl;
    for (auto &pair : customers1)
    {
        printf("[%d, %d] ", pair[0], pair[1]);
    }
    printf("\n");

    return 0;
}
