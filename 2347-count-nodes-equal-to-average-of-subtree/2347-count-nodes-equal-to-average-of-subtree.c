/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int treeSum(struct TreeNode* root){
    return root ? root->val + treeSum(root->left) + treeSum(root->right) : 0;
}

int treeSize(struct TreeNode* root){
    return root ? 1 + treeSize(root->left) + treeSize(root->right) : 0;
}

int valid(struct TreeNode* root){
    return (root->val==floor(treeSum(root)/treeSize(root)));
}

int averageOfSubtree(struct TreeNode* root){
    return root ? valid(root)+averageOfSubtree(root->left)+averageOfSubtree(root->right) : 0;
}