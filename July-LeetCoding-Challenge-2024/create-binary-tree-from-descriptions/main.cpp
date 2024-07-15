#include <vector>
#include <queue>

#include "Solution.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Solution solution;

    // [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
    vector<vector<int>> descriptions = {{20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};
    TreeNode *root = solution.createBinaryTree(descriptions);
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node->left)
        {
            q.push(node->left);
        }
        if (node->right)
        {
            q.push(node->right);
        }
        printf("(%d, %d, %d)\n", node->val, node->left ? node->left->val : -1, node->right ? node->right->val : -1);
    }

    return 0;
}
