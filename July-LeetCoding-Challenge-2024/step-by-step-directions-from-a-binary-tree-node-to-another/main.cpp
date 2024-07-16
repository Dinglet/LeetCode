#include <iostream>

#include "Solution.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Solution solution;
    // root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
    TreeNode *root = new TreeNode(5, new TreeNode(1, new TreeNode(3), nullptr), new TreeNode(2, new TreeNode(6), new TreeNode(4)));

    string pathToStart, pathToDest;
    solution.findPathFromRoot(root, 3, pathToStart);
    solution.findPathFromRoot(root, 6, pathToDest);
    cout << pathToStart << endl;
    cout << pathToDest << endl;
    cout << solution.getDirections(root, 3, 6) << endl;

    return 0;
}
