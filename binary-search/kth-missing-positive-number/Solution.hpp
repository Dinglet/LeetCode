// https://leetcode.com/problems/kth-missing-positive-number/
#include <vector>

using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        // using binary search to find the kth missing number
        int first = 0, last = arr.size();
        while (first < last)
        {
            int mid = first + (last - first) / 2;
            // number of missing numbers before arr[mid] is (arr[mid] - mid - 1)
            if (arr[mid] - mid - 1 < k)
                first = mid + 1;
            else
                last = mid;
        }
        return first + k;
    }

private:
    int findKthPositive0(vector<int> &arr, int k)
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
