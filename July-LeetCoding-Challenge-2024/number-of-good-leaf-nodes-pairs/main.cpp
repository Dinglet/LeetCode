#include <vector>
#include <iostream>

#include "Solution.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Solution solution;
    TreeNode *root;
    int distance;

    // root = [1,2,3,null,4]
    // distance = 3
    root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(4)), new TreeNode(3));
    distance = 3;
    cout << solution.countPairs(root, distance) << endl;

    return 0;
}
