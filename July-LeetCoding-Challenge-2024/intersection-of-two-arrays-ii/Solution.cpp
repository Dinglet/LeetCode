#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> frequencyMap;
        vector<int> result;

        for (int n : nums1)
            frequencyMap[n]++;

        for (int n : nums2)
        {
            if (frequencyMap.find(n) != frequencyMap.end() && frequencyMap[n] > 0)
            {
                result.push_back(n);
                frequencyMap[n]--;
            }
        }

        return result;
    }
};