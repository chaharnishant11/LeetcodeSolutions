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
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            int temp=0;
            for(int i=0;i<n;i++){
                TreeNode* f=q.front();
                q.pop();
                temp+=f->val;
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            ans=temp;
        }
        return ans;
    }
};