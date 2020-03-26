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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if(root==NULL) return ans;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* f=q.front();
                q.pop();
                if(i==n-1){
                    ans.push_back(f->val);
                }
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
        }
        return ans;
    }
};