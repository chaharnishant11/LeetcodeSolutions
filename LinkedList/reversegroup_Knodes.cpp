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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        //ListNode* dummy = new ListNode(-1);
        
        while(curr!=NULL){
            int count =0;
            stack<ListNode*> st;
            ListNode* temp = curr;
            while(curr!=NULL && count<k){
                st.push(curr);
                curr= curr->next;
                count++;  
            }
            if(count==k){
                while(!st.empty()){
                
                    if(prev==NULL){
                        prev = st.top();
                        head = prev;
                        st.pop();
                    }
                
                    else{
                        prev->next = st.top();
                        prev = prev->next;
                        st.pop();
                    }
                
                }
            }
            else {
                while(temp){
                prev->next = temp;
                temp = temp->next;
                prev = prev->next;
                }
            }
        }
        prev->next = NULL; //important
        return head;
    }
};
