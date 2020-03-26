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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            double temp=0;
            for(int i=0;i<n;i++){
                TreeNode* f=q.front();
                q.pop();
                temp+=f->val;
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            temp=temp/n;
            ans.push_back(temp);
        }    
        return ans;
    }
};