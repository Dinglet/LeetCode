// https://leetcode.com/problems/sliding-window-maximum/
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        return maxSlidingWindowDP(nums, k);
    }

    vector<int> maxSlidingWindowHeap(vector<int> &nums, int k)
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

    vector<int> maxSlidingWindowDP(vector<int> &nums, int k)
    {
        const int n = nums.size();
        vector<int> left_max(n);
        vector<int> right_max(n);
        left_max.front() = nums.front();
        right_max.back() = nums.back();
        for (int i = 1; i < n; ++i)
        {
            if (i % k != 0)
                left_max[i] = max(left_max[i], left_max[i - 1]);
        }
        for (int i = n - 1; i--;)
        {
            if (i % k != 0)
                right_max[i] = max(right_max[i], right_max[i + 1]);
        }
        vector<int> output;
        for (int i = 0; i + k <= n; ++i)
        {
            output.push_back(max(right_max[i], left_max[i + k - 1]));
        }
        return output;
    }
};
