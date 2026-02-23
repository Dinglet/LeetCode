// https://leetcode.com/problems/sliding-window-maximum/
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> max_heap;
        for (int i = 0; i + 1 < k; ++i)
        {
            max_heap.push({nums[i], i});
        }
        vector<int> output;
        for (int i = -1; i + k < nums.size(); ++i)
        {
            max_heap.push({nums[i + k], i + k});
            while (max_heap.top().second <= i)
                max_heap.pop();
            output.push_back(max_heap.top().first);
        }
        return output;
    }
};
