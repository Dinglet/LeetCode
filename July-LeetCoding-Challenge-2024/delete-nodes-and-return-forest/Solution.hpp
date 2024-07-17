#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <algorithm>

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
    {
        vector<TreeNode*> forest;
        unordered_map<int, TreeNode*> toParent;
        unordered_map<int, TreeNode*> toNode;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            toNode[node->val] = node;
            if (node->left)
            {
                q.push(node->left);
                toParent[node->left->val] = node;
            }
            if (node->right)
            {
                q.push(node->right);
                toParent[node->right->val] = node;
            }
        }

        forest.push_back(root);

        for (int number : to_delete)
        {
            // printf("Deleting node %d\n", number);
            auto itParent = toParent.find(number);

            // if the node is the root
            if (itParent == toParent.end() || itParent->second == nullptr)
            {
                // printf("Node %d is a root\n", number);

                // printf("Erasing node %d from the forest\n", number);
                forest.erase(find(forest.begin(), forest.end(), toNode[number]));
            }
            else // if the node is not the root
            {
                // disjoin the node from its parent
                TreeNode* parent = itParent->second;
                if (parent->left && parent->left->val == number)
                {
                    parent->left = nullptr;
                }
                else
                {
                    parent->right = nullptr;
                }
            }

            // add its children to the forest
            TreeNode *node = toNode[number];
            if (node -> left)
            {
                // printf("Adding node %d's left child to the forest\n", number);
                forest.push_back(node->left);
                toParent[node->left->val] = nullptr;
            }
            if (node -> right)
            {
                // printf("Adding node %d's right child to the forest\n", number);
                forest.push_back(node->right);
                toParent[node->right->val] = nullptr;
            }
        }

        return forest;
    }
};