// https://leetcode.com/problems/palindrome-partitioning/
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> output;
        vector<string> parts;
        dfs(s, 0, parts, output);
        return output;
    }

private:
    void dfs(const string &s, const size_t pos, vector<string> &parts, vector<vector<string>> &output)
    {
        if (pos == s.size())
        {
            output.push_back(parts);
            return;
        }

        const auto remaining = s.size() - pos;
        for (auto len = 1; len <= remaining; ++len)
        {
            if (isPalindrome(s, pos, len))
            {
                parts.push_back(s.substr(pos, len));
                dfs(s, pos + len, parts, output);
                parts.pop_back();
            }
        }
    }

    bool isPalindrome(const string &s, size_t pos, size_t len)
    {
        auto right = pos + len;
        while (pos < right)
        {
            if (s[pos++] != s[--right])
                return false;
        }
        return true;
    }
};
