#include <iostream>

#include "Solution.hpp"

using namespace std;

int main()
{
    Solution solution;
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> expected{3, 3, 5, 5, 6, 7};

    auto output = solution.maxSlidingWindow(nums, k);

    cout << "Output: ";
    for (const auto &num : output)
        cout << num << " ";
    cout << endl;

    cout << "Expected: ";
    for (const auto &num : expected)
        cout << num << " ";
    cout << endl;

    if (output == expected)
        cout << "Accepted" << endl;
    else
        cout << "Wrong Answer" << endl;
    return 0;
}