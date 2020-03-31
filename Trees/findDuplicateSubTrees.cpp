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
    string helper(TreeNode* root,unordered_map<string,vector<TreeNode*>>& m){
        if(!root) return "";
        string x=to_string(root->val)+","+helper(root->left,m)+","+helper(root->right,m);
        m[x].push_back(root);
        return x;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,vector<TreeNode*>> m;
        vector<TreeNode*> ans;
        string x=helper(root,m);
        for(auto i:m){
            if(i.second.size()>1) ans.push_back(i.second[0]);
        }
        return ans;
    }
};