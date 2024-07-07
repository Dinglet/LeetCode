// https://leetcode.com/problems/water-bottles/

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int remainder;
        int countDrunk = 0;
        while (numBottles >= numExchange)
        {
            // old bottles
            remainder = numBottles % numExchange;
            // new bottles
            numBottles /= numExchange;
            // count drunk
            countDrunk += numBottles * numExchange;

            numBottles += remainder;
        }

        // countDrunk + remainder
        return countDrunk + numBottles;
    }
};