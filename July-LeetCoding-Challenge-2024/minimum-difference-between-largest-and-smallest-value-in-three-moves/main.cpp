#include <iostream>
#include <vector>
#include <cassert>

#include "Solution.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Solution solution;

    printf("Test 1\n");
    vector<int> nums1 = {5,3,2,4};
    assert((solution.minDifference(nums1) == 0));
    printf("\n");

    printf("Test 2\n");
    vector<int> nums2 = {1,5,0,10,14};
    assert((solution.minDifference(nums2) == 1));
    printf("\n");

    printf("Test 3\n");
    vector<int> nums3 = {3,100,20};
    assert((solution.minDifference(nums3) == 0));
    printf("\n");

    std::puts("All test cases passed.");

    return 0;
}
