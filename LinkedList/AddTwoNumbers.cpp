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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        int a=(l1->val+l2->val);
        c=(a>=10)?1:0;
        a=a%10;
        ListNode *ans=new ListNode(a);
        l1=l1->next;
        l2=l2->next;
        ListNode *h=ans;
        while(l1!=NULL || l2!=NULL){
            int x=0;
            x=(((l1)?l1->val:0)+((l2)?l2->val:0) + c);
            c=(x>9)?1:0;
            //cout << l1->val << " " << l2->val <<  endl;
            x=x%10;
            //cout << c << " " << x << endl;
            ListNode *temp=new ListNode(x);
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;
            h->next=temp;
            h=h->next;
            //cout << h->val << " "  << ans->val << endl;
        }
        if(c!=0){
            ListNode *temp=new ListNode(c);
            h->next=temp;
        }
        return ans;
    }
};
