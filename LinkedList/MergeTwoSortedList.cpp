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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1==NULL && l2==NULL) return NULL;
        ListNode* ans;
        ListNode* t;
        if(l1->val>l2->val){
            ans=l2;
            t=l2;
            l2=l2->next;
        }else{
            ans=l1;
            t=l1;
            l1=l1->next;
        }
        while(l1!=NULL && l2!=NULL){
            if(l1->val>l2->val){
                t->next=l2;
                t=t->next;
                l2=l2->next;
            }else{
                t->next=l1;
                l1=l1->next;
                t=t->next;
            }
        }
        while(l1!=NULL){
            t->next=l1;
            l1=l1->next;
            t=t->next;
        }
       while(l2!=NULL){
            t->next=l2;
            l2=l2->next;
            t=t->next;
        }
        return ans;
    }
};
