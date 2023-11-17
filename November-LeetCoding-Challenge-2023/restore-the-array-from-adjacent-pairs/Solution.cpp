#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs)
    {
        unordered_map<int, vector<int>> graph;
        for (auto &pair : adjacentPairs)
        {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }

        vector<int> result;
        result.reserve(adjacentPairs.size() + 1);
        for (auto &node : graph)
        {
            // find the first node with only one adjacent node
            if (node.second.size() == 1)
            {
                result.push_back(node.first);
                result.push_back(node.second[0]);
                break;
            }
        }

        while (result.size() < adjacentPairs.size() + 1)
        {
            auto &last = result[result.size() - 1];
            auto &secondLast = result[result.size() - 2];
            auto &next = graph[last];
            result.push_back(next[0] == secondLast ? next[1] : next[0]);
        }

        return result;
    }
};