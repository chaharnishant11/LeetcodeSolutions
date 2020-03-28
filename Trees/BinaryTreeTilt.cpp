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
    int res=0;
    int helper(TreeNode* root){
        if(root==NULL) return 0;
        int l=helper(root->left);
        int r=helper(root->right);
        res+=abs(l-r);
        return l+r+root->val;
    }
    
    int findTilt(TreeNode* root) {
        if(root==NULL) return 0;
        helper(root);
        return res;
    }
};