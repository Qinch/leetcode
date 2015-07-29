/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        
        ListNode* phead=new ListNode(-1);
        while(head!=NULL)
        {
            ListNode *nhead=head->next;
            ListNode* pc=phead;
            while( (pc->next!=NULL)&&(pc->next->val<head->val) )
            {
                pc=pc->next;
            }
            ListNode *tmp=pc->next;
            pc->next=head;
            head->next=tmp;
            head=nhead;
        }
        return phead->next;
    }
};