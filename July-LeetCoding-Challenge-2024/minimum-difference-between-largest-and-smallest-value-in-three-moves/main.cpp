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

    printf("Test 4\n");
    vector<int> nums4 = {511,526,975,111,71,913,238,734,256,351,454,312,24,502,165,322,154,567,756,63,386,982,900,202,530,598,962,464,950,936,123,591,270,688,479,426};
    assert((solution.minDifference(nums4) == 871));
    printf("\n");

    std::puts("All test cases passed.");

    return 0;
}
