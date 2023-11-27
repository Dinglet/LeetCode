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
        // Group 0: 0
        // 0: 4, 6

        // Group 1: 1, 3, 7, 9
        // 1: 6, 8
        // 3: 4, 8
        // 7: 2, 6
        // 9: 2, 4
        
        // Group 2: 2, 8
        // 2: 7, 9
        // 8: 1, 3

        // Group 3: 4, 6
        // 4: 0, 3, 9
        // 6: 0, 1, 7
        
        // Group 4: 5 (don't care)
        // 5:

        if (n == 1)
            return 10;

        uint64_t dp[4] = {1, 4, 2, 2};
        uint64_t dp2n[4];
        for (int i = 1; i <= n/2; i++)
        {
            dp2n[0] = dp[3];
            dp2n[1] = (dp[2] + dp[2] + dp[3] + dp[3]) % MOD;
            dp2n[2] = dp[1];
            dp2n[3] = (dp[0] + dp[0] + dp[1]) % MOD;

            dp[0] = dp2n[3];
            dp[1] = (dp2n[2] + dp2n[2] + dp2n[3] + dp2n[3]) % MOD;
            dp[2] = dp2n[1];
            dp[3] = (dp2n[0] + dp2n[0] + dp2n[1]) % MOD;
        }
        
        return (n&1) ? (dp[0] + dp[1] + dp[2] + dp[3]) % MOD : (dp2n[0] + dp2n[1] + dp2n[2] + dp2n[3]) % MOD;
    }
};
