#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        // heights is unique
        // order by height in descending order
        map<int, string, greater<int>> heightToName;
        for (int i = 0; i < names.size(); ++i)
        {
            heightToName[heights[i]] = names[i];
        }

        vector<string> result;
        for (auto& [height, name] : heightToName)
        {
            result.push_back(name);
        }

        return result;
    }
};