#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        // since 1 <= n <= 1000 and 1 <= heights[i] <= 100000,
        // we can use higher bits of heights[i] to store the original index of heights[i]
        const int kShift = 17;
        const int kMask = 0x1FFFF;

        for (uint16_t i = 0; i < heights.size(); ++i)
        {
            heights[i] += i << kShift;
        }
        sort(heights.begin(), heights.end(), [&](int a, int b) { return (a & kMask) > (b & kMask); });

        vector<string> result;
        for (uint16_t i = 0; i < heights.size(); ++i)
        {
            string name = names[(uint32_t)heights[i] >> kShift];
            result.push_back(name);
        }

        return result;
    }
};