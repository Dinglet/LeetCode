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

        bool isInSection = false;
        vector<int> nWaysToPutPlants{1};
        for (auto &c : corridor)
        {
            switch (c)
            {
            case 'S':
                isInSection = !isInSection;
                if (!isInSection)
                    nWaysToPutPlants.push_back(1);
                break;
            case 'P':
                if (!isInSection)
                    nWaysToPutPlants.back()++;
                break;
            default:
                break;
            }
        }

        if (isInSection) // the number of seats is odd
            return 0;
        if (nWaysToPutPlants.size() == 1) // the number of seats is even but there is no divider
            return 0;
        
        // ignore the first and last sections
        // return the product of nWaysToPutPlants
        uint64_t nWays = 1;
        for (int i = 1; i < nWaysToPutPlants.size()-1; i++)
            nWays = (nWays * nWaysToPutPlants[i]) % MOD;
        return nWays;
    }
};