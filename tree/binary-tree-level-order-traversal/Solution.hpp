// https://leetcode.com/problems/binary-tree-level-order-traversal/
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> output;
        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty())
        {
            const auto n_current_level_nodes = nodes.size();
            output.push_back({});
            for (auto t = n_current_level_nodes; t--;)
            {
                const auto node = nodes.front();
                nodes.pop();
                output.back().push_back(node->val);

                if (node->left)
                    nodes.push(node->left);
                if (node->right)
                    nodes.push(node->right);
            }
        }
        return output;
    }
};
