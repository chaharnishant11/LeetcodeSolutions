/*
structure of the node of the linked list is
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
};
*/
// complete this function
void mergeList(struct Node **p, struct Node **q)
{
     // Code here
     Node* p_next=*p;
     Node* q_next=*q;
     Node* p_cur=*p;
     Node* q_cur=*q;
     while(q_cur!=NULL && p_cur!=NULL){
         p_next=p_next->next;
         p_cur->next=q_cur;
         p_cur=p_next;
         q_next=q_next->next;
         q_cur->next=p_cur;
         q_cur=q_next;
     }
     *q=q_next;
}