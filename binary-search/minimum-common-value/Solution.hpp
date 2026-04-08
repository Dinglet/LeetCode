// https://leetcode.com/problems/minimum-common-value/
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        auto it1 = nums1.begin(), it2 = nums2.begin();
        while (it1 != nums1.end() && it2 != nums2.end())
        {
            if (*it1 == *it2)
            {
                return *it1;
            }
            else if (*it1 < *it2)
            {
                // find the next element, s.t. it1 >= *it2
                it1 = lower_bound(it1, nums1.end(), *it2);
            }
            else
            {
                it2 = lower_bound(it2, nums2.end(), *it1);
            }
        }
        return -1;
    }
};