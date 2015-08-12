/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 struct ListNode* mergesort(struct ListNode **list, int l,int r)
 {
     if(l==r)
        return l;
    else if(l+1=r)
        merge(list[l],list[r])
    else
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
  struct ListNode *merge(struct ListNode *l1, struct ListNode *l2)
 {
      struct ListNode *h=NULL;
     struct ListNode *t=NULL;
     if(l1==NULL)
        return l2;
     else if(l2==NULL)
        return l1;
     else
     {
        while((l1!=NULL)&&(l2!=NULL))
        {
            struct ListNode *tmp=NULL;
            if(l1->val>l2->val)
            {
                tmp=l2;
                l2=l2->next;
                tmp->next=NULL;
                
            }
            else
            {
                tmp=l1;
                l1=l1->next;
                tmp->next=NULL;
                
            }
            if(h==NULL)
            {
                 h=t=tmp;
            }
            else
            {
                 t->next=tmp;
                t=tmp;
            }
        }
        if(l1==NULL)
            t->next=l2;
        else if(l1!=NULL)
            t->next=l1;
        return h;
     }
 }
 struct ListNode* mergesort(struct ListNode **list, int l,int r)
 {
     if(l==r)
        return list[l];
    else if(l+1==r)
        return merge(list[l],list[r]);
    else
    {
        struct ListNode *lh=mergesort(list,l,(l+r)/2);
        struct ListNode *rh=mergesort(list,(l+r)/2+1,r);
        return merge(lh,rh);
    }
 }
 
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize==0)
        return NULL;
    return mergesort(lists,0,listsSize-1);
}