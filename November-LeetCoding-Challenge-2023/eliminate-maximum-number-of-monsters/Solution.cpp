#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // dist[0] - 0*speed[0] > 0
    // dist[1] - 1*speed[1] > 0
    // dist[2] - 2*speed[2] > 0
    // ...
    // dist[i]/speed[i] > i or (dist[i]-1)/speed[i] >= i
    int eliminateMaximum(vector<int>& dist, vector<int>& speed)
    {
        for (int i = 0; i < dist.size(); i++)
        {
            dist[i] = ((dist[i]-1) / speed[i]);
        }
        sort(dist.begin(), dist.end());

        int count;
        for (count = 0; count < dist.size(); count++)
        {
            if (dist[count] < count)
                return count;
        }
        return count;
    }
};