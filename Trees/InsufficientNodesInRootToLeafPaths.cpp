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
    
    TreeNode* helper(TreeNode* root, int limit, int sum){
        if(!root){
            return NULL;
        }
        if(!root->right && !root->left){
            if(sum + root->val >= limit){
                return root;
            }
            return NULL;
        }
        TreeNode* left, *right;
        left = helper(root->left,limit,sum+root->val);
        right = helper(root->right,limit,sum+root->val);
        root->left = left;
        root->right = right;
        if(!left && !right){
            return NULL;
        }
        return root;
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return helper(root,limit,0);
    }
};