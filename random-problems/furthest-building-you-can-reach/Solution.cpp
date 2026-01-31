// https://leetcode.com/problems/furthest-building-you-can-reach/

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> max_heights;
        for (int i = 0; i + 1 < heights.size(); ++i) {
            int difference = heights[i + 1] - heights[i];
            if (difference <= 0)
                continue;
            if (ladders) {
                // use a ladder
                max_heights.push(difference);
                ladders--;
            } else if (max_heights.size() == 0) {
                // no ladder to use
                bricks -= difference;
            } else {
                max_heights.push(difference);
                // use bricks instead of a ladder
                bricks -= max_heights.top();
                max_heights.pop();
            }
            if (bricks < 0) {
                // cannont reach building `i+1`
                return i;
            }
        }
        // can reach the last building
        return heights.size() - 1;
    }
};
