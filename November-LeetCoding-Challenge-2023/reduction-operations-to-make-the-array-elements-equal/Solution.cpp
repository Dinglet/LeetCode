#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // Time: O(n), Space: O(m) where m is the maximum element in nums
    int reductionOperations(vector<int>& nums)
    {
        vector<int> counts(*max_element(nums.begin(), nums.end()) + 1, 0);
        for (int num : nums)
            counts[num]++;
        
        int nOperations = 0;
        int nToBeReduced = 0;
        for (int i = counts.size() - 1; i >= 0; i--)
        {
            if (counts[i] == 0)
                continue;
            
            nOperations += nToBeReduced;
            nToBeReduced += counts[i];
        }
        
        return nOperations;
    }
};