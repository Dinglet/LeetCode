// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        sort(arr2.begin(), arr2.end());
        int count = 0;
        for (int n : arr1)
        {
            // search for the first index s.t. arr2[i] >= n - d
            const auto first = lower_bound(arr2.begin(), arr2.end(), n - d);
            // check if no element arr2[i] in the range [n - d, n + d]
            count += (first == arr2.end() || *first > n + d);
        }
        return count;
    }
};