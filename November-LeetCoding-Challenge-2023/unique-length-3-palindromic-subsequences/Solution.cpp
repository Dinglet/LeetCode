#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        vector<int> firstPosition(26, -1);
        vector<int> lastPosition(26, -1);
        for (int i = 0; i < s.size(); i++)
        {
            int index = s[i] - 'a';
            if (firstPosition[index]==-1)
                firstPosition[index] = i;
            lastPosition[index] = i;
        }

        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            vector<bool> seen(26, false);
            for (int j = firstPosition[i] + 1; j < lastPosition[i]; j++)
            {
                int index = s[j] - 'a';
                if (!seen[index])
                {
                    seen[index] = true;
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    Solution solution;
    string s;
    
    s = "aabca";
    cout << s+": " << solution.countPalindromicSubsequence(s) << endl;
    return 0;
}