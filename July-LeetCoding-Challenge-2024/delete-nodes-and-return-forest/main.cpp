#include <vector>
#include <iostream>

#include "Solution.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Solution solution;
    TreeNode *root;
    vector<int> to_delete;
    vector<TreeNode *> forest;

    // root = [1,2,null,4,3]
    // to_delete = [2, 3]

    // root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(3)), nullptr);
    // to_delete = {2, 3};
    // forest = solution.delNodes(root, to_delete);

    // for (TreeNode *node : forest)
    // {
    //     cout << node->val << " " << endl;
    // }

    // root = [1,2,3,null,null,null,4]
    // to_delete = [2, 1]

    root = new TreeNode(1, new TreeNode(2, nullptr, nullptr), new TreeNode(3, new TreeNode(4), nullptr));
    to_delete = {2, 1};
    forest = solution.delNodes(root, to_delete);

    for (TreeNode *node : forest)
    {
        cout << node->val << " " << endl;
    }

    return 0;
}
