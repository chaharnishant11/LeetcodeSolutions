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
    set<int> s;
    vector<TreeNode*> ans;
    void helper(TreeNode*& root){
        if(root){
            helper(root->left);
            helper(root->right);
            if(s.find(root->val)!=s.end()){
                if(root->left)ans.push_back(root->left);
                if(root->right)ans.push_back(root->right);
                root=NULL;
                delete root;
            }
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i=0;i<to_delete.size();i++){
            s.insert(to_delete[i]);
        }
        helper(root);
        if(root){
            ans.push_back(root);
        }
        return ans;
    }
};