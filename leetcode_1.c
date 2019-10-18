/*************************************************************************
 > File Name: leetcode_1.c
 > Author: qinchao
 > Mail: 1187620726@qq.com
 > Created Date:2019-10-18 Time:09:04:15.
 ************************************************************************/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void sortNums(int *nums, int *index, int size)
{
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (nums[j] > nums[j+1]) {
                int tmp = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = tmp;
                
                tmp = index[j + 1];
                index[j + 1] = index[j];
                index[j] = tmp;
            }
        }
    }
    return;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    
    int *index = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; ++i) {
        index[i] = i;
    }
    
    sortNums(nums, index, numsSize);
    
    int *ret = malloc(sizeof(int)*2);
    *returnSize = 0;
    
    int i = 0;
    int j = numsSize - 1;
    while (i < j) {
        int sum = nums[i] + nums[j];
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
        ret[0] = index[i];
        ret[1] = index[j];
    }
    free(index);
    index = NULL;  
    return ret;
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


typedef struct Value{
   struct Value *next;
    int key;
    int value;
} Value;

typedef struct {
    Value **bucket;
    int size;
} Hash;

// 根据字符串生成hash的index
unsigned int HASH_GetIndex(int key, int size)
{
    if (key < 0) {
        key = key * -1;
    }
    return key % size;
}

void HASH_Init(Hash *obj)
{
    obj->bucket = malloc(sizeof(Value*) * obj->size);
    memset(obj->bucket, 0, sizeof(Value*) * obj->size);
    return;
}


void HASH_Destroy(Hash *obj)
{
    for (int i = 0; i < obj->size; ++i) {
        Value **walk = &(obj->bucket[i]);
        while((*walk) != NULL) {
            Value *tmp = (*walk);
            *walk = (*walk)->next;
            free(tmp);
            tmp = NULL;
        }
    }
    
    free(obj->bucket);
    obj->bucket = NULL;
    obj->size = 0;
}

// 返回the other index
int HASH_Add(int num, int numIndex, int target, Hash *obj)
{
    int key = target - num;
    int index = HASH_GetIndex(key, obj->size);
    Value **walk = &(obj->bucket[index]);
    
    // *walk为next的值
    while(*walk != NULL) {
        if ((*walk)->key != key) {
            walk = &((*walk)->next);
            continue;
        }
        
        return (*walk)->value;
    }
    
    HASH_Insert(num,  numIndex, obj);
    return -1;
}

HASH_Insert(int key, int value, Hash *obj)
{
    int index = HASH_GetIndex(key, obj->size);
    Value **walk = &(obj->bucket[index]);

    Value *first = (*walk);
    // 如果没找到则insert到hash
    Value *tmp = malloc(sizeof(*tmp));
    tmp->next = first;
    first = NULL;
    
    tmp->key = key;
    tmp->value = value;

    *walk = tmp;
    return;    
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    
    int *ret = malloc(sizeof(int) * 2);
    *returnSize = 0;
    
    Hash obj = {NULL, 1024};
    HASH_Init(&obj);
    
    for (int i = 0; i < numsSize; ++i) {
        int index = HASH_Add(nums[i], i, target, &obj);
        if (index != -1) {
            ret[0] = index;
            ret[1] = i;
            *returnSize = 2;
            break;
        }
    }
    
    HASH_Destroy(&obj);
    return ret;
}
