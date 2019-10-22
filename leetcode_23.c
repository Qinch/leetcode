/*************************************************************************
 > File Name: leetcode_23.c
 > Author: qinchao
 > Mail: 1187620726@qq.com
 > Created Date:2019-10-22 Time:10:51:05.
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *merge2Lists(struct ListNode *list1, struct ListNode *list2)
{
    if (list1 == NULL) {
        return list2;
    }
    
    if (list2 == NULL) {
        return list1;
    }
    
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    while ((list1 != NULL) && (list2 != NULL)) {
        
        struct ListNode *next = NULL;
        if (list1->val < list2->val) {
            
            next = list1;
            list1 = list1->next;
        } else {
            
            next = list2;
            list2 = list2->next;
        }
        
        
       if (head == NULL) {
           head = tail = next;
       } else {
           tail ->next = next;
           tail = next;
       }
       tail->next = NULL;
    }
    
    if (list1 != NULL) {
        tail->next = list1;
    } else if (list2 != NULL) {
        tail->next = list2;
    }
    
    return head;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    
    // 如果lists的size为0, 表示递归终止
    if (listsSize == 0) {
        return NULL;
    }
    if (listsSize == 1) {
        return lists[0];
    }
    
    int mid = listsSize / 2;
    struct ListNode *left = mergeKLists(lists, mid);
    struct ListNode *right = mergeKLists(lists + mid, listsSize - mid);
    return merge2Lists(left, right);
}
