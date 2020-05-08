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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL) return false;
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,NULL});
        while(!q.empty()){
            int n=q.size();
            bool fx=false;
            bool fy=false;
            TreeNode* px=NULL;
            TreeNode* py=NULL;
            for(int i=0;i<n;i++){
                auto p=q.front();
                q.pop();
                //cout <<  n << " :" << i << " :" << p.first->val << " " << x << " " << y << endl;
                if(p.first->val==x){
                    fx=true;
                    px=p.second;
                }
                if(p.first->val==y){
                    fy=true;
                    py=p.second;
                }
                if(p.first->left){
                    q.push({p.first->left,p.first});
                }
                if(p.first->right){
                    q.push({p.first->right,p.first});
                }
            }
            if(fx && fy && px!=py) return true;
        }
        return false;
    }
};