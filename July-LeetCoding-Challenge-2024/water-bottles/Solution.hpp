// https://leetcode.com/problems/water-bottles/

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        // do an exchange to get 1 more bottle
        //     numBottles = numBottles - (numExchange - 1)
        // until numBottles < numExchange
        //     i.e. (numBottles - 1) < (numExchange - 1)
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};