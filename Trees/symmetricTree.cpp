static auto fast=[]{ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();

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
    bool helper(TreeNode* a,TreeNode* b){
        if(!a && !b) return true;
        if(!a || !b) return false;
        return (a->val == b->val) && helper(a->left,b->right) && helper(a->right,b->left);
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root,root);
    }
};