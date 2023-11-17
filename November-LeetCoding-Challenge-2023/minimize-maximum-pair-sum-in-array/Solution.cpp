#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minPairSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n / 2; i++)
            nums[i] += nums[n - i - 1];
        return *max_element(nums.begin(), nums.begin() + n / 2);
    }
};