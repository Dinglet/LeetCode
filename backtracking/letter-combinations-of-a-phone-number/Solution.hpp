// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

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

    vector<string> letterCombinationsNonRecursive(string digits)
    {
        if (digits.size() == 0)
            return {};

        vector<string> combinations;
        string str(digits.size(), 0);
        stack<int> selected_letters;

        do {
            for (auto i_digit = selected_letters.size(); i_digit < digits.size(); ++i_digit) {
                str[i_digit] = digit_map_.at(digits[i_digit])[0];
                selected_letters.push(0);
            }
            combinations.push_back(str);

            do {
                const auto i_letter = selected_letters.top() + 1;
                selected_letters.pop();
                const auto i_digit = selected_letters.size();
                if (i_letter < digit_map_.at(digits[i_digit]).size()) {
                    str[i_digit] = digit_map_.at(digits[i_digit])[i_letter];
                    selected_letters.push(i_letter);
                    break;
                }
            } while (!selected_letters.empty());
        } while (!selected_letters.empty());

        return combinations;
    }
};
