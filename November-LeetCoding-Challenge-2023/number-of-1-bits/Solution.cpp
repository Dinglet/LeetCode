#include <cstdint>

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int hammingWeight = 0;
        while (n)
        {
            n &= (n-1);
            ++hammingWeight;
        }
        return hammingWeight;
    }
};
