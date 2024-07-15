// https://leetcode.com/problems/create-binary-tree-from-descriptions/description/

#include <vector>
#include <unordered_map>
#include <iostream>

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions)
    {
        if (descriptions.empty())
        {
            return nullptr;
        }
        unordered_map<int, TreeNode*> nodes;

        for (const auto &description : descriptions)
        {
            int parent = description[0];
            int child = description[1];
            int isLeft = description[2];

            TreeNode *parentNode = nullptr, *childNode = nullptr;

            // if (isLeft)
            //     printf("(%d, %d, *)\n", parent, child);
            // else
            //     printf("(%d, *, %d)\n", parent, child);

            if (nodes.find(child) == nodes.end())
            {
                // printf("new node %d\n", child);
                // new node
                nodes[child] = new TreeNode(child);
            }
            if (nodes.find(parent) == nodes.end())
            {
                // printf("new node %d\n", parent);
                // new node
                nodes[parent] = new TreeNode(parent);
            }
            if (isLeft)
            {
                nodes[parent]->left = nodes[child];
            }
            else
            {
                nodes[parent]->right = nodes[child];
            }
        }

        for (const auto &description : descriptions)
        {
            int child = description[1];

            if (nodes.find(child) != nodes.end())
            {
                nodes.erase(child);
            }
        }

        return nodes.begin()->second;
    }
};