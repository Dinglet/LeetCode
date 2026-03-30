#include <iostream>

#include "Solution.hpp"

using namespace std;

int main()
{
    Solution solution;
    auto output = solution.partition("aab");
    for (const auto &parts : output)
    {
        for (const auto &part : parts)
            cout << part << " ";
        cout << endl;
    }
    return 0;
}
