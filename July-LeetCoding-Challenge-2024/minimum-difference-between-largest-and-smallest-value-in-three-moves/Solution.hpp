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
            // printf("n <= 4, trivial case\n");
            return 0;
        }

        nth_element(nums.begin(), nums.begin() + 4, nums.end());
        nth_element(nums.begin()+ 4, nums.end() - 4, nums.end());
        sort(nums.begin(), nums.begin() + 4);
        sort(nums.end() - 4, nums.end());

        // printf("mins: %d %d %d %d\n", nums[0], nums[1], nums[2], nums[3]);
        // printf("maxs: %d %d %d %d\n", *(nums.end() - 4), *(nums.end() - 3), *(nums.end() - 2), *(nums.end() - 1));

        int result = *(nums.end() - 4) - *(nums.begin());
        for (int i = 1; i < 4; i++)
        {
            result = min(result, *(nums.end() - 4 + i) - *(nums.begin() + i));
        }

        return result;
    }
};