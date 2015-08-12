/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool IsBalance(struct TreeNode *root,int *depth)
{
    if(root==NULL)
    {
        *depth=0;
        return true;
    }
    int left,right;
    if(IsBalance(root->left,&left)&&IsBalance(root->right,&right))
    {
        int diff=left-right;
        if(diff<=1&&diff>=-1)
        {
            *depth=(diff>=0? left:right)+1;
            return true;
        }
    }
    return false;
}
bool isBalanced(struct TreeNode* root) {
    int depth=0;
    return IsBalance(root,&depth);
}