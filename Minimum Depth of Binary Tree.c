/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if(root==NULL)
        return 0;
    int lhs=minDepth(root->left);
    int rhs=minDepth(root->right);
    if(lhs==0)
        return rhs+1;
    else if(rhs==0)
        return lhs+1;
    else if(lhs>rhs)
        return rhs+1;
    else
        return lhs+1;
}