// { Driver Code Starts
//Author- Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int indx,ans;

struct Node{
    int data;
    Node *left,*right;
    
    Node(int d){
        data=d;
        left=right=NULL;
    }
};
int pairsViolatingBST(Node *root,int n);
void insert(Node *root,int a,int b,char ch);

int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
		indx=0;
		ans=0;
        Node *root=NULL;
        for(int j=0;j<n;j++){
            int a,b;
            char ch;
            cin>>a>>b>>ch;
            if(root==NULL){
                root=new Node(a);
                switch(ch){
                    case 'L':root->left=new Node(b);
                            break;
                    case 'R':root->right=new Node(b);
                            break;
                }
            }else{
                insert(root,a,b,ch);
            }
        }
		cout<<pairsViolatingBST(root,n)<<"\n";
    }

	return 0;
}

void insert(Node *root,int a,int b,char ch){
    if(root==NULL)return;
    if(root->data==a){
        switch(ch){
            case 'L':root->left=new Node(b);
                    break;
            case 'R':root->right=new Node(b);
                    break;
        }
    }else{
        insert(root->left,a,b,ch);
        insert(root->right,a,b,ch);
    }
}
// } Driver Code Ends
/* The structure of Node
struct Node{
    int data;
    Node *left,*right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
}; */


/*You are required to complete below method */
void helper(Node* root,vector<int>& in){
    if(root==NULL) return;
    helper(root->left,in);
    in.push_back(root->data);
    helper(root->right,in);
}

int merge(vector<int>& a,int* temp,int s,int m,int e){
    int ans=0;
    int i=s,j=m+1,k=s;
    while((i<=m) && (j<=e)){
        if(a[i]<a[j]){
            temp[k++]=a[i++];
        }else{
            temp[k++]=a[j++];
            ans+=m-i+1;
        }
    }
    while(i<=m) temp[k++]=a[i++];
    while(j<=e) temp[k++]=a[j++];
    for(i=s;i<=e;i++) a[i]=temp[i];
    return ans;
}

int mergeSortHelper(vector<int>& a,int* temp,int s,int e){
    if(s>=e) return 0;
    int mid=(e+s)/2;
    int ans=0;
    int m=1000000009;
    int l=mergeSortHelper(a,temp,s,mid);
    int r=mergeSortHelper(a,temp,mid+1,e);
    ans=merge(a,temp,s,mid,e);
    return ((ans%m+l%m)%m+r%m)%m;
}

int mergeSort(vector<int>& a, int n){ 
    int temp[n]; 
    return mergeSortHelper(a, temp, 0, n - 1); 
} 

int pairsViolatingBST(Node *root,int n){
    /*Your code here */
    vector<int> in;
    helper(root,in);
    int ans=0;
    ans=mergeSort(in,n+1);
    return ans;
}
