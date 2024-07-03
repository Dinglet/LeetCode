// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/
/**
 * This problem can be thought of as a problem of finding the minimum difference between the maximum and minimum values of an array after removing 3 elements.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minDifference(vector<int>& nums)
    {
        if (nums.size() <= 4)
        {
            printf("n <= 4, trivial case\n");
            return 0;
        }

        sort(nums.begin(), nums.end());
        for (int n : nums)
            printf("%d ", n);
        printf("\n");

        int minDiff = nums[nums.size()-4] - nums[0];
        printf("%d = %d - %d\n", nums[nums.size()-4] - nums[0], nums[nums.size()-4], nums[0]);

        for (int i = 1; i < 4; i++)
        {
            minDiff = min(minDiff, nums[nums.size()-4+i] - nums[i]);
            printf("%d = %d - %d\n", nums[nums.size()-4+i] - nums[i], nums[nums.size()-4+i], nums[i]);
        }

        return minDiff;
    }
};