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
        int tail = 0, head = s.size() - 1;
        int direction = 1;
        for (int len = s.size(); len > 0; --len)
        {
            // assertion: abs(head - tail) + 1 == len
            for (int i = 0; i < s.size() - len; ++i)
            {
                if (isBalanced(count_letters))
                    return len;
                --count_letters[s[tail] - 'a'];
                tail += direction;
                head += direction;
                ++count_letters[s[head] - 'a'];
            }
            if (isBalanced(count_letters))
                return len;
            --count_letters[s[tail] - 'a'];
            tail += direction;
            swap(tail, head);
            direction = -direction;
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