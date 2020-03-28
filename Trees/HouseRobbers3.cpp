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
    int helper(TreeNode* root,int& lm,int& rm){
        if(root==NULL) return 0;
        int ll=0,lr=0,rr=0,rl=0;
        lm=helper(root->left,ll,lr);
        rm=helper(root->right,rl,rr);
        return max(root->val+ll+lr+rr+rl,lm+rm);
    }
    int rob(TreeNode* root) {
        if(root==NULL) return 0;
        int lm=0,rm=0;
        int res=helper(root,lm,rm);
        return res;
    }
};