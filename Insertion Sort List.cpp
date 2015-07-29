/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
       // printf("%u\n",head);
        vector<ListNode*> vec;
        ListNode* p=head;
        while(p!=NULL)
        {
            vec.push_back(p);
            p=p->next;
        }
        for(int i=1;i<vec.size();i++)
        {
            int pCurr=vec[i]->val;
            int j=i-1;
            while( (j>=0)&&(pCurr< vec[j]->val) )
            {
                vec[j+1]->val=vec[j]->val;
                j--;
            }
            vec[j+1]->val=pCurr;
        }
        return head;
    }
};