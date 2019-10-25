/*************************************************************************
 > File Name: leetcode_2.c
 > Author: qinchao
 > Mail: 1187620726@qq.com
 > Created Date:2019-10-25 Time:10:21:19.
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    
    
    int carray = 0;
    while ((l1 != NULL) && (l2 != NULL)) {
        // node val
        int num = l1->val + l2->val + carray;
        carray = (num >= 10 ? 1:0);
        num = num % 10;

        l1 = l1->next;
        l2 = l2->next;
        
        // insert new node
        struct ListNode *node = malloc(sizeof(*node));
        node->val = num;
        node->next = NULL;
        
        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        
    }
    
    struct ListNode *left = NULL;
    if (l1 != NULL) {
        left = l1;
    }
    
    if (l2 != NULL) {
        left = l2;
    }
    
    while (left != NULL) {
        int num = left->val + carray;
        carray = (num >= 10 ? 1 : 0);
        num = num % 10;
       
        printf("carrya:%d\n", carray);
        left = left->next;
        
        // insert new node
        struct ListNode *node = malloc(sizeof(*node));
        node->val = num;
        node->next = NULL;
        tail->next = node;
        tail = node;
    }
    
    if (carray > 0) {
        // insert new node
        struct ListNode *node = malloc(sizeof(*node));
        node->val = carray;
        node->next = NULL;
        tail->next = node;
    }
    
    return head;
}
