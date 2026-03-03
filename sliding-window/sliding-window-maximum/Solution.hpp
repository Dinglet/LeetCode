// https://leetcode.com/problems/sliding-window-maximum/
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        return maxSlidingWindowDeque(nums, k);
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

    vector<int> maxSlidingWindowDeque(vector<int> &nums, int k)
    {
        const int n = nums.size();
        deque<int> candidate_indices;
        vector<int> output(n - k + 1);

        for (int right = 0, left = 0; right < n; ++right)
        {
            // the current window is [left, right]
            // remove the elements smaller than the current one
            while (!candidate_indices.empty() && nums[candidate_indices.back()] < nums[right])
                candidate_indices.pop_back();
            // candidate for the maximum element in the sliding window
            candidate_indices.push_back(right);

            // remove the element out of the current window
            if (left > candidate_indices.front())
                candidate_indices.pop_front();

            // if the length of the current window reaches k
            if (right + 1 >= k)
            {
                // add the maximum element to the output
                output[left++] = nums[candidate_indices.front()];
            }

        }

        return output;
    }
};
