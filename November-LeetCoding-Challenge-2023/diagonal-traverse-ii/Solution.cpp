#include <vector>
#include <iostream>
#include <list>

using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums)
    {
        int nRows = nums.size();
        int nNums = 0;
        for (auto &row : nums)
            nNums += row.size();
        
        vector<int> result;
        result.reserve(nNums);

        list<pair<int, int>> nextRowColIndexPairs;
        for (int iRow = 0; iRow < nRows; iRow++)
        {
            if (nums[iRow].size() > 0)
                nextRowColIndexPairs.push_back({iRow, 0});
        }
        
        int iDiagonal = 0;
        while (!nextRowColIndexPairs.empty())
        {
            // go forward and get the last row with row index iRow <= iDiagonal
            auto it = nextRowColIndexPairs.begin();
            while (next(it) != nextRowColIndexPairs.end() && it->first < iDiagonal)
                it++;
            
            // backward
            while (it != nextRowColIndexPairs.end())
            {
                result.push_back(nums[it->first][it->second]);
                it->second++;
                if (it->second >= nums[it->first].size())
                    it = nextRowColIndexPairs.erase(it);
                it--;
            }
            iDiagonal++;
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    // nums = [[1,2,3],[4,5,6],[7,8,9]]
    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> result = solution.findDiagonalOrder(nums);

    for (auto num : result)
        printf("%d ", num);
    printf("\n");
    return 0;
}
