/*
Counting Bits
https://leetcode.com/problems/counting-bits/description/
*/
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> numberOfSetBits(num+1);
        unsigned int i;
        for(int i=1; i<=num; i+=1)
        {
            numberOfSetBits[i] = numberOfSetBits[i>>1] + (i&1);
        }
        return numberOfSetBits;
    }
};
