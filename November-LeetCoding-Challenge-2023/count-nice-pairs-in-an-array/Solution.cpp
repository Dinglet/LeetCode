#include <vector>
#include <unordered_map>

using namespace std;

#define MOD 1000000007

class Solution
{
public:
    int countNicePairs(vector<int>& nums)
    {
        // compute the difference between num[i] and its reverse
        for (auto &num : nums)
            num -= reverse(num);
        
        // build a frequency map
        unordered_map<int, int> freqencyMap;
        for (auto num : nums)
            freqencyMap[num]++;
        
        // count the number of nice pairs
        int nNicePairs = 0;
        for (auto [key, value] : freqencyMap)
        {
            nNicePairs += ((uint64_t)value * (value - 1) / 2) % MOD;
            nNicePairs %= MOD;
        }
        return nNicePairs;
    }

    // assume n is non-negative
    int reverse(int n)
    {
        int reversed = 0;
        while (n)
        {
            reversed = reversed * 10 + n % 10;
            n /= 10;
        }
        return reversed;
    }
};