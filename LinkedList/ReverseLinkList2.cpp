ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(B != 1){ // if B is not the first element 
        A->next = reverseBetween(A->next, B-1, C-1);// pass the next element decreasing B and C
        return A;
    }
    else{ // if B is the first element
        ListNode *prev=NULL, *curr=A, *next=NULL;
        int count=0;
        while(count<C){ // reverse the list till C 
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        A->next = curr;// Append the first list element to the C+1 element
        return prev;// return the new start
    }
}

