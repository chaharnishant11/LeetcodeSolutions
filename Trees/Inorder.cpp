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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode* curr=root;
        while(curr!=NULL || !s.empty()){
            while(curr){
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            ans.push_back(curr->val);
            curr=curr->right;
        }
        return ans;
        
    }
};