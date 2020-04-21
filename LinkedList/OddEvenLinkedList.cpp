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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        ListNode* h1=head;
        ListNode* h2=head->next;
        ListNode* t2=h2;
        while(t2 && t2->next){
            h1->next=t2->next;
            h1=h1->next;
            t2->next=h1->next;
            t2=t2->next;
        }
        h1->next=h2;
        return head;
    }
};