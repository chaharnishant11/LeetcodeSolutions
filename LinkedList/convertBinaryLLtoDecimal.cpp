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
    int getDecimalValue(ListNode* head) {
        ListNode *curr=head;
        ListNode *n=NULL;
        ListNode *p=NULL;
        while(curr!=NULL){
            n=curr->next;
            curr->next=p;
            p=curr;
            curr=n;
        }
        int ans=0;
        int i=0;
        curr=p;
        while(curr!=NULL){
            ans+=pow(2,i)*curr->val;
            curr=curr->next;
            i++;
        }
        return ans;
    }
};
