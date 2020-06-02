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
    map<pair<int,int>,vector<TreeNode*>> m;
    vector<TreeNode*> helper(int s,int e){
        vector<TreeNode*> res;
        if(s>e){
            res.push_back(NULL);
            return res;
        }
        if(s==e){
            TreeNode* root=new TreeNode(s);
            res.push_back(root);
            return res;
        }
        if(m.find({s,e})!=m.end()) return m[{s,e}];
        vector<TreeNode*> Left,Right;
        for(int i=s;i<=e;i++){
            Left=helper(s,i-1);
            Right=helper(i+1,e);
            for(auto l:Left){
                for(auto r:Right){
                    TreeNode* root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    res.push_back(root);
                }
            }
        }
        m[{s,e}]=res;
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        return helper(1,n);
        
    }
};