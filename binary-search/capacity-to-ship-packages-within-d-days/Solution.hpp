// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        // binary search the least weight capacity in [max(weights), sum(weights) + 1)
        int first = weights[0], last = 0;
        for (int i = 0; i + 1 < weights.size(); ++i)
        {
            first = max(first, weights[i + 1]);
            weights[i + 1] += weights[i];
        }
        last = weights.back() + 1;

        while (first < last)
        {
            const int mid = first + (last - first) / 2;
            int required_days = 1;
            int loaded_weight = 0;
            for (int i = 0; i + 1 < weights.size() && required_days <= days; ++i)
            {
                if (weights[i + 1] > loaded_weight + mid)
                {
                    ++required_days;
                    loaded_weight = weights[i];
                }
            }

            if (required_days <= days)
            {
                last = mid;
            }
            else
            {
                first = mid + 1;
            }
        }
        return first;
    }
};