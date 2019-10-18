/*************************************************************************
 > File Name: leetcode_167.c
 > Author: qinchao
 > Mail: 1187620726@qq.com
 > Created Date:2019-10-18 Time:08:50:52.
 ************************************************************************/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){

    int *ret = malloc(sizeof(int)*2);
    *returnSize = 0;
    
    int i = 0;
    int j = numbersSize - 1;
    while (i < j) {
        int sum = numbers[i] + numbers[j];
        if (sum == target) {
            break;
        }
        
        if (sum < target) {
            ++i;
        } else {
            --j;
        }
    }
    
    if (i != j) {
        *returnSize = 2;
        ret[0] = i + 1;
        ret[1] = j + 1;
    }
    
    return ret;
}
