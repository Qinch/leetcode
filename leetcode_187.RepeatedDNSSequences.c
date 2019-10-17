G/*************************************************************************
 > File Name: leetcode_187.RepeatedDNSSequences.c
 > Author: qinchao
 > Mail: 1187620726@qq.com
 > Created Date:2019-10-17 Time:11:40:44.
 ************************************************************************/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// Hash: key为10个字符串， value为字符串，和对应的计数
typedef struct Value{
   struct Value *next;
   char str[11];
   int count;
} Value;

typedef struct {
    Value **bucket;
    int size;
} Hash;

// 根据字符串生成hash的index
unsigned int HASH_GetIndex(char *str, int len, int size)
{
  unsigned int h = 5381;
  for (int i = 0; i < len; ++i) {
      h= (h << 5) + h + str[i];
  }

  return h % size;
}

void HASH_Init(Hash *obj)
{
    obj->bucket = malloc(sizeof(Value*) * obj->size);
    memset(obj->bucket, 0, sizeof(Value*) * obj->size);
    return;
}

// 在hash中查找str，如果找到count加1;如果没有找到就把该str insert到hash
void HASH_Add(char *str, int len, Hash *obj)
{
    int index = HASH_GetIndex(str, len, obj->size);
    Value **walk = &(obj->bucket[index]);
    
    // *walk为next的值
    while(*walk != NULL) {
        if (strncmp(str, (*walk)->str, len) != 0) {
            walk = &((*walk)->next);
            continue;
        }
        
        // 如果str找到
        ++((*walk)->count);
        break;
    }
    
    if ((*walk) == NULL) {
        // 如果没找到则insert到hash
        Value *tmp = malloc(sizeof(*tmp));
        strncpy(tmp->str, str, len);
        tmp->str[10] = 0;
        tmp->count = 1;
        tmp->next = NULL;
        *walk = tmp;
    }
    
    return;
}

void HASH_Get(Hash *obj, char **p, int *size)
{
    *size = 0;
    for (int i = 0; i < obj->size; ++i) {
        Value **walk = &(obj->bucket[i]);

        // *walk为next的值
        while((*walk) != NULL) {
            if ((*walk)->count > 1) {
                p[*size] = malloc(sizeof(char) * 11);
                strcpy(p[*size], (*walk)->str);
                ++(*size);
            }
            walk = &((*walk)->next);
        }
    }
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

char ** findRepeatedDnaSequences(char * s, int* returnSize){
    
    Hash obj = {NULL, 10240};
    HASH_Init(&obj);
    
    int len = strlen(s);
    for (int i = 0; i < len - 9; ++i) {
        HASH_Add(&s[i], 10, &obj);
    }

    char **p = malloc(sizeof(char*) * 64);
    HASH_Get(&obj, p, returnSize);
    
    HASH_Destroy(&obj);
    return p;
}




#define STATS_LEN (0x01<<20)
unsigned char g_stats[STATS_LEN];

inline int getBin(char c) 
{
    
    int ret = 0;
    switch(c) {
        case 'A':
            ret = 0;
            break;
        case 'C':
            ret = 1;
            break;
        case 'G':
            ret = 2;
            break;
        case 'T':
            ret = 3;
            break;
    }
    
    return ret;
}

int getCombinedInt(char *str, int len)
{
    int total = 0;
    for (int i = 0; i < len; ++i) {
        total = (total << 2) | getBin(str[i]);
    }
    
    return total;
} 


void HASH_Init()
{
    memset(g_stats, 0, STATS_LEN);
    return;
}

// 在hash中查找str，如果找到count加1;如果没有找到就把该str insert到hash
int HASH_Add(char *str, int len)
{
    int key = getCombinedInt(str, len);
    
    if (g_stats[key] < 3) {
        ++g_stats[key];
    }
    
    return g_stats[key];
}


char ** findRepeatedDnaSequences(char * s, int* returnSize){
    HASH_Init();

    char **p = malloc(sizeof(char*) * 64);
    *returnSize = 0;
    
    int len = strlen(s);
    for (int i = 0; i < len - 9; ++i) {
        int r = HASH_Add(&s[i], 10);
        
        // 是否是重复元素，如果是添加到返回数组
        if (r == 2) {
            p[*returnSize] = malloc(sizeof(char) * 11);
            strncpy(p[*returnSize], &s[i], 10);
            p[*returnSize][10] = 0;
            ++(*returnSize);
        }
    }

    return p;
}
