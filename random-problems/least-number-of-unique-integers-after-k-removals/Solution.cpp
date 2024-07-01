// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k)
    {
        sort(arr.begin(), arr.end());

        // count the frequency of each number
        vector<int> freq;
        int i = 0, j = 0;
        while(i < arr.size())
        {
            while(j < arr.size() && arr[j] == arr[i]) j++;
            freq.push_back(j-i);
            i = j;
        }

        // sort the frequency
        sort(freq.begin(), freq.end());

        // remove the least frequent numbers
        for(i = 0; i < freq.size(); i++)
        {
            if(k >= freq[i])
                k -= freq[i];
            else
                break;
        }
        return freq.size() - i;
    }
};