/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ListNode* fast=A;
    ListNode* slow=A;
    while(fast && fast->next && slow){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            ListNode* temp=A;
            while(temp!=slow){
                slow=slow->next;
                temp=temp->next;
            }
            return slow;
        }
    }
    return NULL;
}
