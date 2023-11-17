#include <iostream>
#include <vector>

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
    vector<int> findMode(TreeNode* root)
    {
        vector<int> modes = {0};
        int currentValue = 0;
        int currentCount = 0;
        int maxCount = 0;

        traverse(root, currentValue, currentCount, maxCount, modes);

        return modes;
    }

private:
    void traverse(const TreeNode* node, int &currentValue, int &currentCount, int &maxCount, vector<int> &modes)
    {
        if (node == nullptr)
        {
            return;
        }

        traverse(node->left, currentValue, currentCount, maxCount, modes);

        // Update value and count
        if (node->val == currentValue)
        {
            currentCount++;
        }
        else
        {   
            currentValue = node->val;
            currentCount = 1;
        }

        // Update max count and modes
        if (currentCount == maxCount)
        {
            modes.push_back(currentValue);
        }
        else if (currentCount > maxCount)
        {
            maxCount = currentCount;

            if (modes.size() > 0)
            {
                modes.clear();
                modes.push_back(currentValue);
            }
        }

        traverse(node->right, currentValue, currentCount, maxCount, modes);
    }
};
