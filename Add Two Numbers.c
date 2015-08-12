/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
int lenstr(struct ListNode *h,struct ListNode **t)
{
    struct ListNode *tmp=h;
    int len=0;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
        len++;
    }
    *t=tmp;
    return len;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if(l1==NULL)
        return l2;
    else if(l2==NULL)
        return l1;
    else
    {
        struct ListNode *tail=NULL;
        struct ListNode *t1=NULL;
        struct ListNode *t2=NULL;
        int len1=lenstr(l1,&t1);
        int len2=lenstr(l2,&t2);
        struct ListNode *i1=NULL;
        struct ListNode *i2=NULL;
        if(len1>len2)
        {
            i1=l1;
            tail=t1;
            i2=l2;
        }
        else
        {
            i1=l2;
            tail=t2;
            i2=l1;
        }
        int flag=0;
      
        struct ListNode *head=i1;
        while(i1!=NULL)
        {
            if(i2!=NULL)
            {
                i1->val=i1->val+i2->val+flag;
                flag=i1->val/10;
                i1->val=i1->val%10;
                i1=i1->next;;
                i2=i2->next;
            }
            else
            {
                i1->val=i1->val+flag;
                flag=i1->val/10;
                i1->val=i1->val%10;
                i1=i1->next;
                if(flag==0)
                    break;
            }
        }
        if(flag)
        {
                struct ListNode *tmp=malloc(sizeof(struct ListNode));
                tmp->val=flag;
                tmp->next=NULL;
                tail->next=tmp;
        }
        return head;
    }
  
    
}