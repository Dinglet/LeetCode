// https://leetcode.com/problems/assign-elements-to-groups-with-constraints

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int max_group_size = *max_element(groups.begin(), groups.end());
        vector<int> lookup_table(1 + max_group_size, -1);
        for (int i = 0; i < elements.size(); ++i) {
            int divisor = elements[i];
            if (divisor > max_group_size)
                continue;
            if (lookup_table[divisor] >= 0)
                continue;
            for (int n = divisor; n <= max_group_size; n += divisor) {
                if (lookup_table[n] == -1)
                    lookup_table[n] = i;
            }
            if (divisor == 1)
                break;
        }

        vector<int> result;
        for (int size : groups) {
            result.push_back(lookup_table[size]);
        }
        return result;
    }
};
