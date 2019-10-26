/*************************************************************************
 > File Name: leetcode_328.c
 > Author: qinchao
 > Mail: 1187620726@qq.com
 > Created Date:2019-10-26 Time:08:56:26.
 ************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    
    if (head == NULL) {
        return NULL;
    }
    
    
    struct ListNode *tail = head;
    struct ListNode *even = head->next;
    while(even != NULL && even->next != NULL) {
        struct ListNode *odd = even->next;
        even->next = odd->next;
        
        struct ListNode *tmp = tail->next;
        tail->next = odd;
        tail = odd;
        tail->next = tmp;
        
        even = even->next;
    }
    
    return head;
}
