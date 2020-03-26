
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> s;
        stack<int> a;
        s.push(root);
        while(!s.empty()){
            TreeNode* t=s.top();
            s.pop();
            a.push(t->val);
            if(t->left) s.push(t->left);
            if(t->right) s.push(t->right);
            
        }
        while(!a.empty()){
            ans.push_back(a.top());
            a.pop();
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()) {
            auto cur = stk.top();
            result.push_back(cur->val);
            stk.pop();
            if(cur->left) stk.push(cur->left);
            if(cur->right) stk.push(cur->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};