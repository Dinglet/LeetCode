#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // https://stackoverflow.com/a/47846874
    // pre-condition: v is alphabetic ASCII, upper or lower case
    inline bool isVowel(char c)
    {
        return (0x208222>>(c&0x1f))&1;
    }
    inline size_t vowelIndex(char c)
    {
        switch (c)
        {
        case 'A':
            return 0;
        case 'E':
            return 1;
        case 'I':
            return 2;
        case 'O':
            return 3;
        case 'U':
            return 4;
        case 'a':
            return 5;
        case 'e':
            return 6;
        case 'i':
            return 7;
        case 'o':
            return 8;
        case 'u':
            return 9;
        default:
            return -1;
        }
    }
    string sortVowels(string s)
    {
        vector<int> vowelCounts(10, 0);

        for (char c : s)
        {
            if (isVowel(c))
            {
                vowelCounts[vowelIndex(c)]++;
            }
        }

        queue<char> charQueue({'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'});

        for (char &c : s)
        {
            if (isVowel(c))
            {
                while (vowelCounts[vowelIndex(charQueue.front())] == 0)
                {
                    charQueue.pop();
                }
                c = charQueue.front();
                vowelCounts[vowelIndex(charQueue.front())]--;
            }
        }

        return s;
    }
};

int main(int argc, char const *argv[])
{
    string s, t;
    Solution solution;

    // // Input: s = "lEetcOde"
    // // Output: "lEOtcede"
    // s = "lEetcOde";
    // t = solution.sortVowels(s);
    // cout << t << endl;

    vector<char> vowels({'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'});

    for (auto v : vowels)
    {
        if (v >= 65 && v <= 90)
        {
            cout << (int)v << ": " << ((v-'A')) << endl;
        }
        else if (v >= 97 && v <= 122)
        {
            cout << (int)v << ": " << ((v-'a')) << endl;
        }
        else
        {
            cout << (int)v << ": " << "error" << endl;
        }
    }

    return 0;
}
