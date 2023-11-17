#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <set>
#include <queue>

using namespace std;

class Solution
{
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target)
    {
        if (source == target)
            return 0;

        int maxStop = max(source, target);
        for (const auto &route : routes)
        {
            for (int stop : route)
            {
                maxStop = max(maxStop, stop);
            }
        }

        // vector<bool> seen(maxStop + 1, false);
        // vector<bool> criticalStopFlags(maxStop + 1, false);
        // criticalStopFlags[source] = true;
        // criticalStopFlags[target] = true;
        // for (const auto &route : routes)
        // {
        //     for (int stop : route)
        //     {
        //         if (seen[stop])
        //             criticalStopFlags[stop] = true;
        //         seen[stop] = true;
        //     }
        // }
        
        // vector<vector<int>> newRoutes;
        // for (const auto &route : routes)
        // {
        //     newRoutes.push_back({});
        //     for (int stop : route)
        //     {
        //         if (criticalStopFlags[stop])
        //         {
        //             newRoutes.back().push_back(stop);
        //         }
        //     }
        // }

        int nRoutes = routes.size();
        vector<int> nBusesToReach(maxStop + 1, numeric_limits<int>::max());
        nBusesToReach[source] = 0;

        bool going = true;
        do
        {
            going = false;
            for (const auto& route : routes)
            {
                int min = numeric_limits<int>::max();
                for (int stop : route)
                {
                    min = std::min(min, nBusesToReach[stop]);
                }
                if (min == numeric_limits<int>::max())
                    continue;

                min++;
                for (int stop : route)
                {
                    if (nBusesToReach[stop] > min)
                    {
                        nBusesToReach[stop] = min;
                        going = true; // keep going until no more changes
                    }
                }
            }
        } while (going);

        return (nBusesToReach[target] == numeric_limits<int>::max()) ? -1 : nBusesToReach[target];
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int source, target, expected;

    // vector<vector<int>> routes = {
    //     {1, 2, 7},
    //     {3, 6, 7}
    // };
    // source = 1, target = 6, expected;

    // int result = solution.numBusesToDestination(routes, source, target);
    // cout << result << endl;

    // vector<vector<int>> routes2 = {
    //     {7, 12},
    //     {4, 5, 15},
    //     {6},
    //     {15, 19},
    //     {9, 12, 13}
    // };
    // source = 15, target = 12;

    // result = solution.numBusesToDestination(routes2, source, target);
    // cout << result << endl;

    // // route = [[24],[3,6,11,14,22],[1,23,24],[0,6,14],[1,3,8,11,20]]
    // // source = 20
    // // target = 8
    // vector<vector<int>> routes3 = {
    //     {24},
    //     {3, 6, 11, 14, 22},
    //     {1, 23, 24},
    //     {0, 6, 14},
    //     {1, 3, 8, 11, 20}
    // };
    // source = 20, target = 8;

    // result = solution.numBusesToDestination(routes3, source, target);
    // cout << result << endl;

    // route = [[0,4,15],[17,20],[4,11,14,16,23],[1,12,15,16],[0,6,8,10]]
    // source = 10
    // target = 0
    vector<vector<int>> routes4 = {
        {0, 4, 15},
        {17, 20},
        {4, 11, 14, 16, 23},
        {1, 12, 15, 16},
        {0, 6, 8, 10}
    };
    source = 10, target = 0, expected = 1;
    cout << solution.numBusesToDestination(routes4, source, target) << endl;

    return 0;
}
