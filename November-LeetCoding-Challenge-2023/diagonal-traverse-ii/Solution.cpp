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
        nextRowColIndexPairs.push_back({0, 0});
        
        int iDiagonal = 0;
        while (!nextRowColIndexPairs.empty())
        {
            auto it = nextRowColIndexPairs.begin();
            
            while (it != nextRowColIndexPairs.end())
            {
                int iRow = it->first;
                int iCol = it->second;

                if (iCol < nums[iRow].size())
                {
                    result.push_back(nums[iRow][iCol]);
                    it->second++;
                    it++;
                }
                else
                {
                    it = nextRowColIndexPairs.erase(it);
                }
            }

            iDiagonal++;
            if (iDiagonal < nRows)
            {
                nextRowColIndexPairs.push_front({iDiagonal, 0});
            }
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
    
    // nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
    vector<vector<int>> nums2 = {{1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16}};
    vector<int> result2 = solution.findDiagonalOrder(nums2);

    for (auto num : result2)
        printf("%d ", num);
    printf("\n");
    return 0;
}
