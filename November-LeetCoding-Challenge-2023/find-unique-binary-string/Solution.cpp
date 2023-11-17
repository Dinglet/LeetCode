#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string findDifferentBinaryString(vector<string>& nums)
    {
        const int n = nums.size();
        const int len = nums[0].size();

        if (n >= (1 << len))
        {
            return "";
        }

        // using Cantor's Diagonal Argument
        string s(len, '0');
        for (int i = 0; i < len; ++i)
        {
            if (nums[i][i] == '0')
            {
                s[i] = '1';
            }
        }

        return s;
    }
};