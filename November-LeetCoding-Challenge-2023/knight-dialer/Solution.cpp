#include <vector>
#include <cstdint>
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
        uint64_t dp2n[10];
        for (int i = 1; i <= n/2; i++)
        {
            dp2n[0] = (dp[4] + dp[6]) % MOD;
            dp2n[1] = (dp[6] + dp[8]) % MOD;
            dp2n[2] = (dp[7] + dp[9]) % MOD;
            dp2n[3] = (dp[4] + dp[8]) % MOD;
            dp2n[4] = (dp[0] + dp[3] + dp[9]) % MOD;
            dp2n[5] = 0;
            dp2n[6] = (dp[0] + dp[1] + dp[7]) % MOD;
            dp2n[7] = (dp[2] + dp[6]) % MOD;
            dp2n[8] = (dp[1] + dp[3]) % MOD;
            dp2n[9] = (dp[2] + dp[4]) % MOD;

            dp[0] = (dp2n[4] + dp2n[6]) % MOD;
            dp[1] = (dp2n[6] + dp2n[8]) % MOD;
            dp[2] = (dp2n[7] + dp2n[9]) % MOD;
            dp[3] = (dp2n[4] + dp2n[8]) % MOD;
            dp[4] = (dp2n[0] + dp2n[3] + dp2n[9]) % MOD;
            dp[5] = 0;
            dp[6] = (dp2n[0] + dp2n[1] + dp2n[7]) % MOD;
            dp[7] = (dp2n[2] + dp2n[6]) % MOD;
            dp[8] = (dp2n[1] + dp2n[3]) % MOD;
            dp[9] = (dp2n[2] + dp2n[4]) % MOD;
        }
        
        return (n&1) ? accumulate(dp, dp + 10, 0ULL) % MOD : accumulate(dp2n, dp2n + 10, 0ULL) % MOD;
    }
};
