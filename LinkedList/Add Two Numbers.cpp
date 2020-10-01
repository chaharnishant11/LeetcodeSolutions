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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=NULL, *tail=NULL;
        int c= 0;
        while(l1 or l2 or c) {
            int a=0, b=0;
            if(l1) {
                a=l1->val; l1= l1->next;
            }
            if(l2) {
                b= l2->val; l2= l2->next;
            }
            int ans= (a+b+c)%10;
            c= (a+b+c)/10;
            ListNode* temp =new ListNode(ans);
            if(!tail) {
                head= temp;
                tail= temp;
            } else {
                tail->next= temp; tail= temp;
            }
        }
        return head;
    }
};
