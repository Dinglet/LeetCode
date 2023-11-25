#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums)
    {
        vector<int> result;
        result.reserve(nums.size());

        int absoluteSum = accumulate(nums.begin(), nums.end(), 0) - (nums[0] * nums.size());
        result.push_back(absoluteSum);

        for (int i = 1; i < nums.size(); ++i)
        {
            int difference = nums[i]-nums[i-1];
            // absoluteSum += difference * i - difference * (nums.size()-i);
            absoluteSum += difference * (2*i - nums.size());
            result.push_back(absoluteSum);
        }

        return result;
    }
};
