class Solution {
public:
    int mySqrt(int x)
    {
        int loopTimes = 8*sizeof(int)/2;
        if(x<0) return -1;
        unsigned int window = 3 << (loopTimes-1)*2;
        unsigned int q = 0, a = 0, b = 0;
        while(loopTimes--)
        {
            q = (q<<2) | ((x&window) >> loopTimes*2);
            a = (a|b)<<1;
            b = (a<<1 | 1) > q ? 0 : 1;
            q -= b ? (a<<1 | 1) : 0;
            window >>= 2;
        }
        return a|b;
    }
    int mySqrt_binarySearch(int x)
    {
        int low=0, high=x, mid;
        int y;
        if(x<2) return x;
        while(high-low > 1) // there is something between
        {
            mid = (low+high)/2;
            if(mid <= x/mid)
                low=mid;
            else
                high=mid;
        }
        return low;
    }
};
