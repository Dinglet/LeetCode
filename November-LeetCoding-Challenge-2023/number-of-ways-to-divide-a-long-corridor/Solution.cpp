#include <string>
#include <vector>
#include <numeric>

using namespace std;

#define MOD 1000000007

class Solution
{
public:
    int numberOfWays(string corridor)
    {
        // walk through the corridor from left to right (0 to n-1)
        // once two seats are occupied
        // install one divider to the left of the left seat
        // and install another divider to the right of the right seat
        // the goal is to find the number of ways to put plants into sections

        int nWays = 1;
        int nWaysToPutPlants = 1;
        bool isInSection = false;
        
        int iLeftmostSeat = 0, iRightmostSeat = corridor.size() - 1;
        while (iLeftmostSeat <= iRightmostSeat && corridor[iLeftmostSeat] == 'P')
            iLeftmostSeat++;
        while (iRightmostSeat >= iLeftmostSeat && corridor[iRightmostSeat] == 'P')
            iRightmostSeat--;
        if (iLeftmostSeat >= iRightmostSeat)
            return 0;
        
        int i = iLeftmostSeat;
        while (i <= iRightmostSeat)
        {
            switch (corridor[i++])
            {
            case 'S':
                isInSection = !isInSection;
                if (!isInSection)
                {
                    nWays = ((uint64_t)nWays * nWaysToPutPlants) % MOD;
                    nWaysToPutPlants = 1;
                }
                break;
            case 'P':
                if (!isInSection)
                    nWaysToPutPlants++;
                break;
            default:
                break;
            }
        }

        if (isInSection) // the number of seats is odd
            return 0;
        
        return nWays;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    // corridor = "SPPPPPPPSPPPSPSSSPPPPPPPPPPPPPPPPPSPPPPPPPPPPPPPPPPSPPPPPSPSPPPPPPSPSPPSPSPPPSPSPPSSPPPPPSPPSSPP"
    string corridor = "SPPPPPPPSPPPSPSSSPPPPPPPPPPPPPPPPPSPPPPPPPPPPPPPPPPSPPPPPSPSPPPPPPSPSPPSPSPPPSPSPPSSPPPPPSPPSSPP";
    int nWays = solution.numberOfWays(corridor);
    printf("%d\n", nWays);
    return 0;
}
