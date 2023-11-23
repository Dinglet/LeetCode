#include <vector>
#include <algorithm>
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
            int maxElement = *max_element(nums.begin() + l[i], nums.begin() + (r[i] + 1));
            int minElement = *min_element(nums.begin() + l[i], nums.begin() + (r[i] + 1));
            int nElements = r[i] - l[i] + 1;

            if (maxElement == minElement)
            {
                result.push_back(true);
                continue;
            }
            if ((maxElement - minElement) % (nElements - 1) != 0)
            {
                result.push_back(false);
                continue;
            }
            int difference = (maxElement - minElement) / (nElements - 1);

            // check apperance of minElement + appears[i] * difference
            vector<bool> appears(nElements, false);
            bool isArithmetic = true;
            for (int j = l[i]; j <= r[i]; j++)
            {
                if ((nums[j] - minElement) % difference != 0)
                {
                    isArithmetic = false;
                    break;
                }
                int index = (nums[j] - minElement) / difference;
                if (appears[index])
                {
                    isArithmetic = false;
                    break;
                }
                appears[index] = true;
            }
            result.push_back(isArithmetic);
        }
        return result;
    }
};
