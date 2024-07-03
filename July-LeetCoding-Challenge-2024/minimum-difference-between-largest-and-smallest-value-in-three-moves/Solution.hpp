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

        vector<int> mins = {kMax, kMax, kMax, kMax}; // 4 smallest elements
        vector<int> maxs = {kMin, kMin, kMin, kMin}; // 4 largest elements

        for (int n : nums)
        {
            if (n < mins[0])
            {
                mins[3] = mins[2];
                mins[2] = mins[1];
                mins[1] = mins[0];
                mins[0] = n;
            }
            else if (n < mins[1])
            {
                mins[3] = mins[2];
                mins[2] = mins[1];
                mins[1] = n;
            }
            else if (n < mins[2])
            {
                mins[3] = mins[2];
                mins[2] = n;
            }
            else if (n < mins[3])
            {
                mins[3] = n;
            }

            if (n > maxs[3])
            {
                maxs[0] = maxs[1];
                maxs[1] = maxs[2];
                maxs[2] = maxs[3];
                maxs[3] = n;
            }
            else if (n > maxs[2])
            {
                maxs[0] = maxs[1];
                maxs[1] = maxs[2];
                maxs[2] = n;
            }
            else if (n > maxs[1])
            {
                maxs[0] = maxs[1];
                maxs[1] = n;
            }
            else if (n > maxs[0])
            {
                maxs[0] = n;
            }
        }

        // printf("mins: %d %d %d %d\n", mins[0], mins[1], mins[2], mins[3]);
        // printf("maxs: %d %d %d %d\n", maxs[0], maxs[1], maxs[2], maxs[3]);

        int result = maxs[0] - mins[0];
        for (int i = 1; i < 4; i++)
        {
            result = min(result, maxs[i] - mins[i]);
        }

        return result;
    }
private:
    const int kMin = -1e9;
    const int kMax = 1e9;
};