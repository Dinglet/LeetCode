// https://leetcode.com/problems/crawler-log-folder/

#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    /**
     * Constraints:
     * - 1 <= logs.length <= 103
     * - 2 <= logs[i].length <= 10
     * - logs[i] contains lowercase English letters, digits, '.', and '/'.
     * - logs[i] follows the format described in the statement.
     * - Folder names consist of lowercase English letters and digits.
     */
    int minOperations(vector<string>& logs)
    {
        int depth = 0;
        for (const auto &log : logs)
        {
            if (log == "../")
            {
                if (depth > 0)
                    depth--;
            }
            else if (log != "./")
            {
                depth++;
            }
        }

        return depth;
    }
};