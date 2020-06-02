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
    vector<vector<int>> ans;
    void helper(TreeNode* root,int sum,vector<int>& path){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            int temp;
            path.push_back(root->val);
            for(int i=0;i<path.size();i++) temp+=path[i];
            if(sum==temp) ans.push_back(path);
            return;
        }
        vector<int> temp=path;
        path.push_back(root->val);
        temp.push_back(root->val);
        helper(root->left,sum,path);
        helper(root->right,sum,temp);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        helper(root,sum,path);
        return ans;
    }
};