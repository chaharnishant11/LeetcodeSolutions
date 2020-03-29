// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}
// } Driver Code Ends
/*struct Node
{
	int data;
	Node *left, *right;
};*/

Node* helper(int* post,int s,int e){
    if(s>e) return NULL;
    int val=post[e];
    Node* root=new Node(val);
    int index=0;
    while(true){
        if(post[index]>val || index>e-1) break;
        index++;
    }
    root->left=helper(post,s,index-1);
    root->right=helper(post,index,e-1);
    return root;
}

Node *constructTree (int post[], int size)
{
//code here
    return helper(post,0,size-1);
}