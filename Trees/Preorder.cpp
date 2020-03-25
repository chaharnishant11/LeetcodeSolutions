/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> s;
        TreeNode* curr=root;
        s.push(curr);
        while(!s.empty()){
            TreeNode* f=s.top();
            s.pop();
            ans.push_back(f->val);
            if(f->right) s.push(f->right);
            if(f->left) s.push(f->left);
            
        }
        return ans;
    }
};