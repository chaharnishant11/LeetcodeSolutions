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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            num++;
        }
        //cout << num << endl;
        if(num==1 || num==0) return NULL;
        if(n>num) return head;
        if(n==num) return head->next;
        n=num-n-1;
        temp=head;
        int i=0;
        while(i<n){
            temp=temp->next;
            i++;
        }
        //cout << temp->val << endl;
        if(temp->next!=NULL && temp->next->next!=NULL){
            temp->next=temp->next->next;
        }else{
            temp->next=NULL;
        }
        return head;
    }
};
