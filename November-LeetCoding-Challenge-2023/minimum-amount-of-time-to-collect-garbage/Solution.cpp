#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    // in garbage, each string consists only of the characters 'M', 'P', and 'G'
    int garbageCollection(vector<string>& garbage, vector<int>& travel)
    {
        int n = garbage.size();
        vector<bool> isGarbageCollected(3, true);
        int totalGarbageCollectedTime = 0;

        // travel from back to front
        for (int i = n-1; i>0; i--)
        {
            for (char c : garbage[i])
            {
                switch (c)
                {
                    case 'M':
                        isGarbageCollected[0] = false;
                        totalGarbageCollectedTime++;
                        break;
                    case 'P':
                        isGarbageCollected[1] = false;
                        totalGarbageCollectedTime++;
                        break;
                    case 'G':
                        isGarbageCollected[2] = false;
                        totalGarbageCollectedTime++;
                        break;
                    default:
                        break;
                }
            }

            // if there is garbage to be collected at this location
            // add the travel time to the garbage collected time
            if (!isGarbageCollected[0])
                totalGarbageCollectedTime += travel[i-1];
            if (!isGarbageCollected[1])
                totalGarbageCollectedTime += travel[i-1];
            if (!isGarbageCollected[2])
                totalGarbageCollectedTime += travel[i-1];
        }
        for (char c : garbage[0])
        {
            switch (c)
            {
                case 'M':
                    totalGarbageCollectedTime++;
                    break;
                case 'P':
                    totalGarbageCollectedTime++;
                    break;
                case 'G':
                    totalGarbageCollectedTime++;
                    break;
                default:
                    break;
            }
        }
        
        return totalGarbageCollectedTime;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    // garbage = ["G","P","GP","GG"]
    // travel = [2,4,3]
    vector<string> garbage = {"G","P","GP","GG"};
    vector<int> travel = {2,4,3};
    int result = solution.garbageCollection(garbage, travel);
    cout << result << endl;
    return 0;
}
