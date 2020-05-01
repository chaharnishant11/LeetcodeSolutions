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
    bool helper(TreeNode* root,vector<int>& a,int i){
        if(root->val!=a[i]) return false;
        if(i==a.size()-1) return !root->left&&!root->right;
        return (root->left && helper(root->left,a,i+1)) || (root->right && helper(root->right,a,i+1));

    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if(!root) return arr.size()==0;
        return helper(root,arr,0);
    }
};