// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/

#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s)
    {
        stack<size_t> positionsOfLeftParentheses;

        for (size_t i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case '(':
                positionsOfLeftParentheses.push(i);
                break;
            case ')':
                size_t left = positionsOfLeftParentheses.top();
                size_t right = i;
                positionsOfLeftParentheses.pop();
                reverse(s.begin() + left + 1, s.begin() + right);
                break;
            }
        }

        string result;
        result.reserve(s.size());
        for (auto c : s)
        {
            if (c != '(' && c != ')')
            {
                result.push_back(c);
            }
        }

        return result;
    }
};