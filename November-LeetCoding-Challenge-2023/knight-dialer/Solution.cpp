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
        
        uint64_t dp[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        for (int i = 1; i < n; i++)
        {
            uint64_t next[10] =
            {
                (dp[4] + dp[6]) % MOD,
                (dp[6] + dp[8]) % MOD,
                (dp[7] + dp[9]) % MOD,
                (dp[4] + dp[8]) % MOD,
                (dp[0] + dp[3] + dp[9]) % MOD,
                0,
                (dp[0] + dp[1] + dp[7]) % MOD,
                (dp[2] + dp[6]) % MOD,
                (dp[1] + dp[3]) % MOD,
                (dp[2] + dp[4]) % MOD
            };

            memcpy(dp, next, sizeof(dp));
        }

        return accumulate(dp, dp + 10, 0ULL) % MOD;
    }
};