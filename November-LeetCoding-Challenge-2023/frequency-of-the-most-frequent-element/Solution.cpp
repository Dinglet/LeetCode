#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    // For each increment in the frequency of an element nums[j] less than nums[i],
    // we should choose nums[j] as close to nums[i] as possible to save the cost.
    int maxFrequency(vector<int>& nums, int k)
    {
        map<int, int> freqencyMap;
        for (int num : nums)
        {
            freqencyMap[num]++;
        }

        int maxFrequency = 0;
        for (auto it = freqencyMap.rbegin(); it != freqencyMap.rend(); it++)
        {
            int num = it->first;
            int frequency = it->second;
            int accIncrement = 0;

            auto it1 = it;
            it1++;
            for (; it1 != freqencyMap.rend(); it1++)
            {
                int num1 = it1->first;
                int frequency1 = it1->second;
                int difference = num - num1;
                int nIncrement = min(frequency1, (k-accIncrement)/difference);

                if(nIncrement == 0)
                    break;
                
                accIncrement += nIncrement * difference;
                frequency += nIncrement;
            }
            if (frequency > maxFrequency)
            {
                maxFrequency = frequency;
            }
        }
        return maxFrequency;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 4};
    int k = 5;
    int result = solution.maxFrequency(nums, k);
    cout << result << endl;
    return 0;
}