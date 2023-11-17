#include <vector>

using namespace std;

class Solution
{
public:
    // The integer arr[0] wins k consecutive rounds if arr[1], ..., arr[k] are less than arr[0].
    int getWinner(vector<int>& arr, int k)
    {
        int defender = arr[0];
        int nWins = 0;
        
        for (int i = 1; i < arr.size(); ++i)
        {
            if (arr[i] < defender)
            {
                ++nWins;
            }
            else
            {
                defender = arr[i];
                nWins = 1;
            }
            if (nWins == k)
            {
                return defender;
            }
        }

        return defender;
    }
};