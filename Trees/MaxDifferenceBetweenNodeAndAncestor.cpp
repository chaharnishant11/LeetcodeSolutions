/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    void helper(TreeNode* root,int maxv,int minv){
        if(root==NULL) return;
        maxv=max(maxv,root->val);
        minv=min(minv,root->val);
        ans=max(ans,abs(maxv-minv));
        helper(root->left,maxv,minv);
        helper(root->right,maxv,minv);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        helper(root,root->val,root->val);
        return ans;
    }
};