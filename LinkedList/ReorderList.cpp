/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode *p = head;
        ListNode *q = getMidNode(head);   
        q = reverseList(q);
        mergeList(p,q);
    } 
    
    ListNode* getMidNode(ListNode* head){
        ListNode *slow= head,*fast= head;
        while(slow && fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return mid;        
    }
    
    ListNode* reverseList(ListNode *root){
        ListNode* prev = NULL, *next = root, *curr = root;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
        // returning head of reversed list
    }
    
    void mergeList(ListNode* p, ListNode* q){
        ListNode* tmp;
        while(q){
            tmp = p->next;  // store address of next
            p->next = q;    // link to 2nd list
            q = q->next;    // increase 2nd list pointer
            p = p->next;    
            p->next = tmp;  // link to 1st list
            p = p->next;    // increase 1st list pointer
        }
    }
};