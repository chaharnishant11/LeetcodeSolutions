/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode* sorted=new ListNode(INT_MIN);
    ListNode* temp=sorted;
    ListNode* curr=A;
    while(curr){
        ListNode* next=curr->next;
        temp=sorted;
        while(temp->next && temp->next->val<curr->val) temp=temp->next;
        if(temp->next){
            curr->next=temp->next;
            temp->next=curr;
        }else{
            temp->next=new ListNode(curr->val);
        }
        curr=next;
    }
    return sorted->next;
}
