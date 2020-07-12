/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* start) {
    ListNode* dummy = new ListNode(0); 
    dummy -> next = start; 
    ListNode* prev = dummy; 
    ListNode* current = start; 
    while(current != NULL) { 
        while(current -> next != NULL && prev -> next -> val == current -> next -> val) 
            current = current -> next; 
        if (prev -> next == current) 
            prev = prev -> next; 
        else
            prev -> next = current -> next; 
  
        current = current -> next; 
    } 
    start = dummy -> next;
    return start;
}
