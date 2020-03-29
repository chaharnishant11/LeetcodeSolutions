
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "x,";
        return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
    }
    
    queue<string> split(string data){
        queue<string> q;
        int i=0;
        while(i<data.size()){
            if(data[i]==','){
                i++;
                continue;
            } 
            int j=i;
            while(i<data.size() && data[i]!=',') i++;
            string x=data.substr(j,i-j);
            q.push(x);
        }
        return q;
    }
    
    TreeNode* helper(queue<string>&q){
        if(q.front()=="x"){
            q.pop();
            return NULL;
        }
        TreeNode* root=new TreeNode(stoi(q.front()));
        q.pop();
        root->left=helper(q);
        root->right=helper(q);
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0]=='x') return NULL;
        queue<string> q=split(data);
        return helper(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));