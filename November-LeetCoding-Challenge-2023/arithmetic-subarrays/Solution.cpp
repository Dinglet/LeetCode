#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r)
    {
        vector<bool> result;
        result.reserve(l.size());

        for (int i = 0; i < l.size(); i++)
        {
            vector<int> subarray(nums.begin() + l[i], nums.begin() + (r[i] + 1));
            sort(subarray.begin(), subarray.end());
            int difference = subarray[1] - subarray[0];
            bool isArithmetic = true;
            for (int j = 2; j < subarray.size(); j++)
            {
                if (subarray[j] - subarray[j - 1] != difference)
                {
                    isArithmetic = false;
                    break;
                }
            }
            result.push_back(isArithmetic);
        }
        return result;
    }
};
