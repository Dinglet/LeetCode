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

class Solution {
public:
    int averageOfSubtree(TreeNode* root)
    {
        int count = 0;
        int sum = 0;
        return countNodesValueEqualToAverageOfSubtree(root, count, sum);
    }
    
    int countNodesValueEqualToAverageOfSubtree(TreeNode* root, int &count, int &sum)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int leftCount = 0;
        int leftSum = 0;
        int leftResult = countNodesValueEqualToAverageOfSubtree(root->left, leftCount, leftSum);

        int rightCount = 0;
        int rightSum = 0;
        int rightResult = countNodesValueEqualToAverageOfSubtree(root->right, rightCount, rightSum);

        count = leftCount + rightCount + 1;
        sum = leftSum + rightSum + root->val;
        
        return leftResult + rightResult + (sum/count == root->val ? 1 : 0);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
