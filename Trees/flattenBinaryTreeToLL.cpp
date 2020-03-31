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
    void flatten(TreeNode* root) {
        if(!root) return;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* t=s.top();
            s.pop();
            if(t->right)s.push(t->right);
            if(t->left)s.push(t->left);
            if(t->left) t->right=t->left;
            else if(!t->left && !s.empty()) t->right=s.top();
            t->left=NULL;
        }
    }
};