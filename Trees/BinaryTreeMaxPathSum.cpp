class Solution {
public:
    int ans;
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        helper(root);
        return ans;
    }
    int helper(TreeNode* root){
        if(root==NULL) return 0;
        int l=max(0,helper(root->left));
        int r=max(0,helper(root->right));
        ans=max(ans,l+r+root->val);
        return max(l,r)+root->val;
    }
};