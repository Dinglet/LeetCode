// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return {};

        vector<string> combinations;
        string s(digits.size(), 'a');
        dfs(digits, s, 0, combinations);
        return combinations;
    }

private:
    const unordered_map<char, string> digit_map_
    {
        {'2', "abc"}, {'3', "def"},
        {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    void dfs(const string &digits, string &s, int i, vector<string> &combinations)
    {
        if (i == digits.size())
        {
            combinations.push_back(s);
            return;
        }
        for (char c : digit_map_.at(digits[i]))
        {
            s[i] = c;
            dfs(digits, s, i + 1, combinations);
        }
    }
};
