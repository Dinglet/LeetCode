// https://leetcode.com/problems/maximum-number-of-coins-you-can-get/

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // get the second largest in each triplet
    // thus, the result is the sum of the 2nd, 4th, 6th, ..., and (piles.size()/3)*2-th largest elements in piles
    int maxCoins(vector<int>& piles)
    {
        sort(piles.begin(), piles.end());
        
        int myCoins = 0;
        for (int i = piles.size() / 3; i < piles.size(); i += 2)
        {
            myCoins += piles[i];
        }
        return myCoins;
    }
};