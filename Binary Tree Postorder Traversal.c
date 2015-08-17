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
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode *sk[100];
    int flag[100]={0};
    int sp=0;
    int *arr=malloc(sizeof(int)*100);
    *returnSize=0;
    struct TreeNode *p=root;
    while(p||sp)
    {
        if(p)
        {
            sk[sp++]=p;
            p=p->left;
        }
        else if(flag[sp-1]==0)
        {
            p=sk[sp-1]->right;
            flag[sp-1]=1;
        }
        else
        {
            flag[--sp]=0;
            arr[*returnSize]=sk[sp]->val;
            (*returnSize)++;
        }
    }
    return arr;
}