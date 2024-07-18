#include <queue>
#include <unordered_map>
#include <unordered_set>

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
    int countPairs(TreeNode* root, int distance)
    {
        int result = 0;

        unordered_map<TreeNode*, TreeNode*> toParent;
        unordered_map<TreeNode*, int> toDepth;
        unordered_set<TreeNode*> leafNodes;
        {
            toParent[root] = nullptr;
            toDepth[root] = 0;

            queue<TreeNode*> q;
            q.push(root);

            while (!q.empty())
            {
                TreeNode* node = q.front();
                q.pop();

                if (node->left == nullptr && node->right == nullptr)
                {
                    // inset leaf node
                    leafNodes.insert(node);
                }
                if (node->left != nullptr)
                {
                    q.push(node->left);
                    toDepth[node->left] = toDepth[node] + 1;
                    toParent[node->left] = node;
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                    toDepth[node->right] = toDepth[node] + 1;
                    toParent[node->right] = node;
                }
            }
        }

        for (auto leaf : leafNodes)
        {
            printf("leaf: %d\n", leaf->val);
        }

        for (auto leaf : leafNodes)
        {
            for (auto otherLeaf : leafNodes)
            {
                if (leaf == otherLeaf)
                {
                    continue;
                }

                int countDistance = 0;
                TreeNode* node = leaf;
                TreeNode* otherNode = otherLeaf;

                while (countDistance <= distance && node != otherNode)
                {
                    if (toDepth[node] > toDepth[otherNode])
                    {
                        node = toParent[node];
                        countDistance += 1;
                    }
                    else if (toDepth[node] < toDepth[otherNode])
                    {
                        otherNode = toParent[otherNode];
                        countDistance += 1;
                    }
                    else
                    {
                        node = toParent[node];
                        otherNode = toParent[otherNode];
                        countDistance += 2;
                    }
                }

                if (countDistance <= distance)
                {
                    result += 1;
                }
            }
        }
        result /= 2;
        return result;
    }
};