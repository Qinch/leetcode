*
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
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if(preorderSize<=0||inorderSize<=0)
        return NULL;
    struct TreeNode* root=malloc(sizeof(struct TreeNode));
    int mid=preorder[0];
    int left=findMid(inorder,inorderSize,mid);
    root->val=mid;
    root->left=buildTree(preorder+1,left,inorder,left);
    root->right=buildTree(preorder+left+1,preorderSize-left-1,inorder+left+1,inorderSize-left-1);
    return root;
}