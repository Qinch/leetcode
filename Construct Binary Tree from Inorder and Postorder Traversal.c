/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int findMid(int* inorder,int size,int x)//在中序遍历中寻找x元素;
 {
     int i=0;
     for(;i<size;i++)
     {
         if(inorder[i]==x)
            return i;
     }
 }
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if(inorderSize<=0||postorderSize<=0)
        return NULL;
    struct TreeNode *root=malloc(sizeof(struct TreeNode));
    int mid=postorder[postorderSize-1];
    int left=findMid(inorder,inorderSize,mid);
    root->val=mid;
    root->left=buildTree(inorder,left,postorder,left);
    root->right=buildTree(inorder+left+1,inorderSize-left-1,postorder+left,postorderSize-left-1);
    return root;
}