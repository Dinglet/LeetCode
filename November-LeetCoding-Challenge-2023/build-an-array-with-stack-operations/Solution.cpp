// https://leetcode.com/problems/build-an-array-with-stack-operations/
// Given an integer array target and an integer n.
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    static const string operations[];

    // When target_i is at the top of the stack
    // target_{i+1} needs target_{i+1} - target_i - 1 "Push" operations
    vector<string> buildArray(vector<int>& target, int n)
    {
        vector<string> result;

        int previous = 0;
        for (int i = 0; i < target.size(); i++)
        {
            int T = target[i]-previous-1;
            while (T--)
            {
                result.push_back(operations[0]);
                result.push_back(operations[1]);
            }
            result.push_back(operations[0]);
            
            previous = target[i];
        }
        return result;
    }
};

const string Solution::operations[] = {"Push", "Pop"};
