// https://leetcode.com/problems/kth-missing-positive-number/
#include <vector>

using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        // check for missing numbers starting from 1
        int missing_number = 1;
        for (int i = 0; i < arr.size(); ++i)
        {
            while (missing_number < arr[i] && k--)
            {
                if (k == 0)
                    return missing_number;
                ++missing_number;
            }
            // missing_number is arr[i], but arr[i] is not missing
            ++missing_number;
            // missing_number is now arr[i] + 1, which is the next number to check for missing
        }
        return missing_number + k - 1;
    }
};
