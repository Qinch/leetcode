/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
 struct ListNode *pCurr=head;
    struct ListNode *ret=NULL;
    while(pCurr!=NULL)
    {
        struct ListNode *pNext=pCurr->next;
        while((pNext!=NULL)&&(pCurr->val==pNext->val))
        {
            struct ListNode *tmp=pNext;
            pNext=pNext->next; 
            free(tmp);
            
        } 
        pCurr->next=pNext;
        pCurr=pNext;
    }
    return head;
}