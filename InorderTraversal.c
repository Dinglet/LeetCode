/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode *new_node(int val)
{
    struct TreeNode *p_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p_node->val = val;
    p_node->left = NULL;
    p_node->right = NULL;
    return p_node;
}
void free_node(struct TreeNode *p_node)
{
    if(!p_node)
        return;
    free_node(p_node->left);
    free_node(p_node->right);
    free(p_node);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    if(!root)
    {
        *returnSize = 0;
        return NULL;
    }
    
    int i;
    int left_size, right_size;
    int *left_array, *right_array, *inorder_array; 
    
    left_array = inorderTraversal(root->left, &left_size);
    right_array = inorderTraversal(root->right, &right_size);
    *returnSize = left_size + right_size + 1;
    
    inorder_array = (int *)malloc(sizeof(int) * (*returnSize));
    
    memmove(inorder_array, left_array, left_size*sizeof(int));
    inorder_array[left_size] = root->val;
    memmove(inorder_array+left_size+1, right_array, right_size*sizeof(int));
    
    free(left_array);
    free(right_array);
    return inorder_array;
}
