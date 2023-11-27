#include <vector>
#include <cstdint>
#include <cstring>
#include <numeric>

using namespace std;

#define MOD 1000000007

class Solution
{
public:
    int knightDialer(int n)
    {
        // 0: 4, 6
        // 1: 6, 8
        // 2: 7, 9
        // 3: 4, 8
        // 4: 0, 3, 9
        // 5:
        // 6: 0, 1, 7
        // 7: 2, 6
        // 8: 1, 3
        // 9: 2, 4
        vector<vector<int>> moves = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};

        uint64_t dp[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        for (int i = 1; i < n; i++)
        {
            uint64_t next[10] = {0};
            for (int j = 0; j < 10; j++)
            {
                for (int k = 0; k < moves[j].size(); k++)
                {
                    next[moves[j][k]] += dp[j];
                    next[moves[j][k]] %= MOD;
                }
            }
            memcpy(dp, next, sizeof(dp));
        }

        return accumulate(dp, dp + 10, 0ULL) % MOD;
    }
};