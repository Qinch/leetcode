/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    
    struct ListNode *pNext=node->next;
    node->val=pNext->val;
    node->next=pNext->next;
    free(pNext);
}