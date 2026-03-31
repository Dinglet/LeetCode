// https://leetcode.com/problems/word-break/
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size() + 1);
        dp.front() = 1;
        for (int i = 0; i < dp.size(); ++i)
        {
            if (!dp[i])
                continue;
            for (const auto &word : wordDict)
            {
                if (s.compare(i, word.size(), word) == 0)
                    dp[i + word.size()] = true;
            }
        }

        return dp.back();
    }
};
