#include <cmath>

class Solution
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        // The case that time is exactly 0
        if (t==1 && fx == sx && fy == sy)
            return false;
        return abs(fx - sx) <= t && abs(fy - sy) <= t && abs(fx - sx) + abs(fy - sy) <= 2*t;
    }
};