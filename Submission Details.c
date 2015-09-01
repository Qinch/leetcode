/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isEqual(struct TreeNode* r1,struct TreeNode* r2)
{
    if(r1==NULL&&r2==NULL)
        return true;
    if(r1==NULL||r2==NULL)
        return false;
    if(r1->val!=r2->val)
        return false;
    return isEqual(r1->left,r2->right)&&isEqual(r1->right,r2->left);
}
bool isSymmetric(struct TreeNode* root) {
   return isEqual(root,root);
}