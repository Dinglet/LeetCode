/*
Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/
#include<unordered_map>
#include<queue>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> hashtable;
        queue<char> candidateSubstring;
        int countMaxLength = 0;

        for(int i=0; i<s.length(); i+=1)
        {
            hashtable[s[i]] = hashtable[s[i]] + 1;
            if(hashtable.size() > countMaxLength)
                countMaxLength = hashtable.size();
            candidateSubstring.push(s[i]);

            if(candidateSubstring.size() > countMaxLength)
            {
                if(hashtable[candidateSubstring.front()] == 1)
                    hashtable.erase(candidateSubstring.front());
                else
                    hashtable[candidateSubstring.front()] -= 1;
                candidateSubstring.pop();
            }
        }
        return countMaxLength;
    }
};
