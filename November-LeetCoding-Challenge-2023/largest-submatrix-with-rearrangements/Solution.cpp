#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution
{
public:
    int largestSubmatrix(vector<vector<int>>& matrix)
    {
        // For each column, count the number of consecutive ones.
        for (int iRow = 1; iRow < matrix.size(); ++iRow)
        {
            for (int iCol = 0; iCol < matrix[iRow].size(); ++iCol)
            {
                if (matrix[iRow][iCol])
                {
                    matrix[iRow][iCol] = 1 + matrix[iRow-1][iCol];
                }
            }
        }

        int maxArea = 0;
        for (auto &row : matrix)
        {
            sort(row.begin(), row.end(), greater<int>());
            for (int iCol = 0; iCol < row.size(); ++iCol)
            {
                maxArea = max(maxArea, (iCol+1) * row[iCol]);
            }
        }
        
        return maxArea;
    }
};