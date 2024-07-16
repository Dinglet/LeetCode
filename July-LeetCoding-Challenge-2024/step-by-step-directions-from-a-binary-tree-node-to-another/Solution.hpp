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
    string getDirections(TreeNode* root, int startValue, int destValue)
    {
        string directions;
        string directionsToStart, directionsToDest;
        findPathFromRoot(root, startValue, directionsToStart);
        findPathFromRoot(root, destValue, directionsToDest);

        int i = 0;
        while (i < directionsToStart.size() && i < directionsToDest.size() && directionsToStart[i] == directionsToDest[i])
        {
            i++;
        }
        // common prefix [0, i)
        directions.assign(directionsToStart.size() - i, 'U');
        directions.append(directionsToDest.begin() + i, directionsToDest.end());
        return directions;
    }

    bool findPathFromRoot(TreeNode *root, int dest, string &path)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->val == dest)
        {
            return true;
        }

        path.push_back('L');
        if (findPathFromRoot(root->left, dest, path))
        {
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if (findPathFromRoot(root->right, dest, path))
        {
            return true;
        }
        path.pop_back();

        return false;
    }
};
