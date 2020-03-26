void leftView(Node *root)
{
   // Your code here
    queue<Node*> q;
    if(root==NULL) return ;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* f=q.front();
            q.pop();
            if(i==0){
                cout << f->data << " ";
            }
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
        }
    }
}

