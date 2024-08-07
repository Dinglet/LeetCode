#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix)
    {
        vector<int> result;
        vector<int> minsInRows; // size = the number of rows
        vector<int> maxsInCols; // size = the number of columns
        minsInRows.resize(matrix.size(), INT_MAX);
        maxsInCols.resize(matrix[0].size(), INT_MIN);

        for (int iRow = 0; iRow < matrix.size(); ++iRow)
        {
            for (int iCol = 0; iCol < matrix[iRow].size(); ++iCol)
            {
                minsInRows[iRow] = min(minsInRows[iRow], matrix[iRow][iCol]);
                maxsInCols[iCol] = max(maxsInCols[iCol], matrix[iRow][iCol]);
            }
        }

        sort(minsInRows.begin(), minsInRows.end());
        sort(maxsInCols.begin(), maxsInCols.end());
        set_intersection(minsInRows.begin(), minsInRows.end(), maxsInCols.begin(), maxsInCols.end(), back_inserter(result));

        return result;
    }
};