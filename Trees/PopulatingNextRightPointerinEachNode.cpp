// O(n) time and O(n) space

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        Node* level_start = root;
        while(level_start!=NULL){
            Node* curr = level_start;
            while(curr!=NULL){
                if(curr->left!=NULL) curr->left->next=curr->right;
                if(curr->right!=NULL && curr->next!=NULL) curr->right->next=curr->next->left;
                curr = curr->next;
            }
            level_start=level_start->left;
        }
        return root;
    }
};

// O(n) time and O(2^log(h)) space

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
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<Node*> temp;
            for(int i=0;i<n;i++){
                Node* f=q.front();
                q.pop();
                temp.push_back(f);
                if(f->left)q.push(f->left);
                if(f->right) q.push(f->right);
            }
            if(temp.size()>0){
                for(int i=0;i<temp.size()-1;i++){
                    temp[i]->next=temp[i+1];
                }
            }
        }
        return root;
    }
};
