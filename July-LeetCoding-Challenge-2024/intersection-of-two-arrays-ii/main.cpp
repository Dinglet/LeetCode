#include <vector>

#include "Solution.hpp"

void generateVector(vector<int> &nums1, vector<int> &nums2);

int main(int argc, char const *argv[])
{
    vector<int> nums1, nums2;
    generateVector(nums1, nums2);

    Solution solution;
    vector<int> result = solution.intersect(nums1, nums2);

    return 0;
}

void generateVector(vector<int> &nums1, vector<int> &nums2)
{
    nums1 = {1, 2, 2, 1};
    nums2 = {2, 2};
}