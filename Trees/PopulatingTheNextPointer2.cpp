/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        Node* prev=NULL;
        Node* curr=root;
        Node* head=NULL;
        while(curr){
            while(curr){
                if(curr->left){
                    if(prev!=NULL){
                        prev->next=curr->left;
                    }else{
                        head=curr->left;
                    }
                    prev=curr->left;
                }if(curr->right){
                    if(prev!=NULL){
                        prev->next=curr->right;
                    }else{
                        head=curr->right;
                    }
                    prev=curr->right;
                }
                curr=curr->next;
            }
            curr=head;
            head=NULL;
            prev=NULL;
        }
        return root;
    }
};