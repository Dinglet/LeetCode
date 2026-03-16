// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *node = root;
        while (node != p && node != q)
        {
            if (node->val > p->val && node->val > q->val)
            {
                // go left
                node = node->left;
            }
            else if (node->val < p->val && node->val < q->val)
            {
                // go right
                node = node->right;
            }
            else
            {
                return node;
            }
        }
        return node;
    }
};
