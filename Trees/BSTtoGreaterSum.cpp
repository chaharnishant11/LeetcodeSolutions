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
    void helper(TreeNode* root,int& val){
        if(root==NULL) return;
        helper(root->right,val);
        val+=root->val;
        root->val=val;
        helper(root->left,val);
        return;
    }    
    
    TreeNode* bstToGst(TreeNode* root) {
        int val=0;
        helper(root,val);
        return root;
    }
};