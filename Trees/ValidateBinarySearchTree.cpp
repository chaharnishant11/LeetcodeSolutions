// Iterative
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        stack<TreeNode*> s;
        vector<int> inorder;
        while(!s.empty()  || root!=NULL){
            while(root){
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            inorder.push_back(root->val);
            root=root->right;
        }
        for(int i=0;i<inorder.size()-1;i++){
            if(inorder[i]>=inorder[i+1]) return false;
        }
        return true;
    }

};

// Recursive

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }

    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if(!root) return true;
        if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
            return false;
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};