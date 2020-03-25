/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

struct node *reverse (struct node *head, int k)
{ 
    // Complete this method
    if(head==NULL or head->next==NULL) return head;
    node* c=head;
    node* p=NULL;
    node* n;
    int i=k;
    while(i-- && c!=NULL){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    head->next=reverse(n,k);
    return p;
}
