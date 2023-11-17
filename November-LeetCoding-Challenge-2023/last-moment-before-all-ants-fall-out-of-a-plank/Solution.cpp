#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right)
    {
        // for ants moving to the left
        auto itRightMostAntToLeft = max_element(left.begin(), left.end());
        int maxDistanceToLeft = left.end()==itRightMostAntToLeft ? 0 : *itRightMostAntToLeft;

        // for ants moving to the right
        auto itLeftmostAntMovingToRight = min_element(right.begin(), right.end());
        int maxDistanceToRight = right.end()==itLeftmostAntMovingToRight ? 0 : n-*itLeftmostAntMovingToRight;

        return max(maxDistanceToLeft, maxDistanceToRight);
    }
};
