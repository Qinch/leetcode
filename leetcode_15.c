/*************************************************************************
 > File Name: leetcode_15.c
 > Author: qinchao
 > Mail: 1187620726@qq.com
 > Created Date:2019-10-24 Time:11:41:40.
 ************************************************************************/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include<stdlib.h>

int cmpFunc(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), cmpFunc);
    
    int len = sizeof(int*)*20000;
    int **ret = (int **)malloc(len);
    *returnColumnSizes = malloc(sizeof(int)*20000);
    int count = 0;
    
    for (int i = 0; i < numsSize - 2; ++i) {
        if ((i > 0) && (nums[i] == nums[i - 1])) {
            continue;
        }
        
        int l = i + 1;
        int r = numsSize - 1;
        while (l < r) {
            int sum = nums[l] + nums[r] + nums[i];
            if (sum == 0) {
                // 存储
                ret[count] = (int*)malloc(sizeof(int) * 3);
                ret[count][0] = nums[i];
                ret[count][1] = nums[l];
                ret[count][2] = nums[r];
                (*returnColumnSizes)[count] = 3;
                count++;
                l++;
                r--;
                while(nums[r] == nums[r + 1] && l < r) {
                    r--;
                }

                while(nums[l] == nums[l - 1] && l < r) {
                    l++;
                }
            } else if (sum > 0) {
                r--;
            } else {
                l++;
            }
        }
        
    }
    
    *returnSize = count;
    return ret;
}
