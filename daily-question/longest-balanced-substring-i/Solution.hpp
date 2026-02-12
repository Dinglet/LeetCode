// https://leetcode.com/problems/longest-balanced-substring-i/
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestBalanced(string s)
    {
        for (int len = s.size(); len > 0; --len)
        {
            vector<int> count_letters(26);
            for (int i = 0; i < len; ++i)
            {
                ++count_letters[s[i] - 'a'];
            }

            for (int i = 0; i + len < s.size(); ++i)
            {
                if (isBalanced(count_letters))
                    return len;
                --count_letters[s[i] - 'a'];
                ++count_letters[s[i + len] - 'a'];
            }
            if (isBalanced(count_letters))
                return len;
        }
        return 0;
    }

    bool isBalanced(const vector<int> &m)
    {
        int target = 0;
        for (auto &&count : m)
        {
            if (count == 0)
                continue;
            if (target != 0 && target != count)
                return false;
            if (target == 0)
                target = count;
        }
        return true;
    }
};