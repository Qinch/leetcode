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
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode *sk[100];
    int sp=0;
    struct TreeNode *p=root;
    int *arr=malloc(sizeof(int)*100);
    *returnSize=0;
    while(p||sp)
    {
        if(p)
        {
            sk[sp++]=p;
            p=p->left;
        }
        else
        {
            p=sk[--sp];
            arr[*returnSize]=p->val;
            (*returnSize)++;
            p=p->right;
        }
    }
    return arr;
}