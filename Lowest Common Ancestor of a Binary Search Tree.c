/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    int min=q->val;
    int max=p->val;
    if(p->val<q->val)
    {
        min=p->val;
        max=q->val;
    }
   
    while(root)
    {
        if(root->val>=min&&root->val<=max)
            return root;
        if(root->val>max)
            root=root->left;
        else 
            root=root->right;
    }
    return NULL;
}