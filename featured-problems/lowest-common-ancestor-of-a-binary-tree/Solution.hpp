#include <string>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        string pathP, pathQ;
        findPath(root, p, pathP);
        findPath(root, q, pathQ);

        TreeNode *lca = root;
        for (size_t i = 0; i < pathP.size() && i < pathQ.size(); i++)
        {
            if (pathP[i] != pathQ[i])
            {
                break;
            }
            if (pathP[i] == 'L')
            {
                lca = lca->left;
            }
            else
            {
                lca = lca->right;
            }
        }

        return lca;
    }
private:
    bool findPath(TreeNode *root, TreeNode *target, string &path)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root == target)
        {
            return true;
        }

        path.push_back('L');
        if (findPath(root->left, target, path))
        {
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, target, path))
        {
            return true;
        }
        path.pop_back();

        return false;
    }
};