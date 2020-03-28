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
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return -1;
        vector<int> in;
        stack<TreeNode*> s;
        TreeNode* curr=root;
        while(!s.empty() || curr){
            while(curr){
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            in.push_back(curr->val);
            curr=curr->right;
        }
        return in[k-1];
    }
};