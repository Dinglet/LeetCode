// https://leetcode.com/problems/longest-balanced-substring-i/
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestBalanced(string s)
    {
        // reusable count of letters in the current substring
        vector<int> count_letters(26);
        for (char c : s)
            ++count_letters[c - 'a'];

        // the left-to-right and right-to-left checks are inspired by cocktail shaker sort
        int len = s.size();
        for (; len > 0;)
        {
            // check if the substring of length `len` is balanced
            // from left to right
            for (int i = 0; i + len < s.size(); ++i)
            {
                if (isBalanced(count_letters))
                    return len;
                --count_letters[s[i] - 'a'];
                ++count_letters[s[i + len] - 'a'];
            }
            if (isBalanced(count_letters))
                return len;

            --count_letters[s[s.size() - len--] - 'a'];
            if (len == 0)
                break;

            // check if the substring of length `len` is balanced
            // from right to left
            for (int i = s.size() - len - 1; i >= 0; --i)
            {
                if (isBalanced(count_letters))
                    return len;
                ++count_letters[s[i] - 'a'];
                --count_letters[s[i + len] - 'a'];
            }
            if (isBalanced(count_letters))
                return len;
            --count_letters[s[--len] - 'a'];
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