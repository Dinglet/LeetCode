// https://leetcode.com/problems/maximum-profit-of-operating-a-centennial-wheel/

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost)
    {
        int iRotation = 0;
        int nRestCustomers = 0, nBoardingCustomers = 0;
        int profit = 0, maxProfit = 0;
        int nOperationsMaxProfit = -1;

        for (iRotation = 0; iRotation < customers.size(); iRotation++)
        {
            // for each rotation
            const int &customer = customers[iRotation];

            // customers arrive
            nRestCustomers += customer;
            // customers board
            nBoardingCustomers = min(4, nRestCustomers);
            nRestCustomers -= nBoardingCustomers;
            profit += nBoardingCustomers * boardingCost - runningCost;

            if (profit > maxProfit)
            {
                maxProfit = profit;
                nOperationsMaxProfit = iRotation + 1;
            }
            // printf("iRotation: %d, nRestCustomers: %d, nBoardingCustomers: %d, profit: %d, maxProfit: %d, nOperationsMaxProfit: %d\n", iRotation, nRestCustomers, nBoardingCustomers, profit, maxProfit, nOperationsMaxProfit);
        }

        while (nRestCustomers > 0)
        {
            // customers board
            nBoardingCustomers = min(4, nRestCustomers);
            nRestCustomers -= nBoardingCustomers;
            profit += nBoardingCustomers * boardingCost - runningCost;

            if (profit > maxProfit)
            {
                maxProfit = profit;
                nOperationsMaxProfit = iRotation + 1;
            }

            // printf("iRotation: %d, nRestCustomers: %d, nBoardingCustomers: %d, profit: %d, maxProfit: %d, nOperationsMaxProfit: %d\n", iRotation, nRestCustomers, nBoardingCustomers, profit, maxProfit, nOperationsMaxProfit);

            iRotation++;
        }

        return nOperationsMaxProfit;
    }
};