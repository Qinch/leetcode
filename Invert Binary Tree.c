/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 void invert(struct TreeNode *p)
 {
     if(p!=NULL)
     { 
         struct TreeNode* left=p->left;
         p->left=p->right;
         p->right=left;
         invert(p->left);
         invert(p->right);
        
     }
     
 }
struct TreeNode* invertTree(struct TreeNode* root) {
    invert(root);
    return root;
    
}