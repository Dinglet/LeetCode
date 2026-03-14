// https://leetcode.com/problems/binary-tree-right-side-view/
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
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return {};

        vector<int> output;
        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty())
        {
            TreeNode *node{};
            for (int t = nodes.size(); t--;)
            {
                node = nodes.front();
                nodes.pop();
                if (node->left)
                    nodes.push(node->left);
                if (node->right)
                    nodes.push(node->right);
            }
            output.push_back(node->val);
        }
        return output;
    }
};
