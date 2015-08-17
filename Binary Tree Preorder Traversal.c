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
 
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode* sk[100];
    int sp=0;
    int *arr=malloc(sizeof(int)*100);
    struct TreeNode *p=root;
    *returnSize=0;
    while(p||sp)
    {
        if(p)
        {
            arr[*returnSize]=p->val;
            (*returnSize)++;
            sk[sp++]=p;
            p=p->left;
        }
        else
        {
            p=sk[--sp]->right;
        }
    }
    return arr;
}