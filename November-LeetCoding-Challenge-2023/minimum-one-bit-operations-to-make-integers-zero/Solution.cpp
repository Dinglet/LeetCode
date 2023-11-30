#include <iostream>

using namespace std;

class Solution
{
public:
    int minimumOneBitOperations(int n)
    {
        // 1 -> 0: 1

        // *10 -> *11
        // -> 01 -> 00: 3
        // 10 -> 11 -> 01 -> 00: 3

        // *100 -> 101 -> 111 -> *110
        // -> 010 -> 011 -> 001 -> 000: 7
        // 100 -> 101 -> 111 -> 110 -> 010 -> 011 -> 001 -> 000: 7

        // *1000 -> 1001 -> 1011 -> 1010 -> 1110 -> 1111 -> 1101 -> *1100
        // -> *0100 -> 0101 -> 0111 -> 0110 -> 0010 -> 0011 -> 0001 -> 0000: 15

        int countOperations = 0;
        unsigned mask = 0xc0000000;
        unsigned powerOfTwo = 0x80000000;
        while (n)
        {
            if (n & powerOfTwo)
            {
                countOperations += powerOfTwo;
                n ^= mask;
            }
            mask >>= 1;
            powerOfTwo >>= 1;
        }
        
        return countOperations;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.minimumOneBitOperations(6) << endl;
    return 0;
}
