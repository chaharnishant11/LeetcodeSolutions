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
    TreeNode* ans=NULL;
    int depth=0;
    int helper(TreeNode* root,int d){
        depth=max(d,depth);
        if(root==NULL) return d;
        int left=helper(root->left,d+1);
        int right=helper(root->right,d+1);
        if(left==depth && right==depth){
            ans=root;
        }
        return max(left,right);
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int x=helper(root,0);
        return ans;
    }
};

