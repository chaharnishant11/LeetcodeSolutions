ALGO 1:
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
    int dfs(unordered_map<TreeNode*,vector<TreeNode*>> m,int k,TreeNode* root,unordered_map<TreeNode*,bool>& vis,unordered_map<int,bool>& ans){     
        if(root==NULL || k<0) return -1;
        if(k==0) return root->val;
        vis[root]=true;
        for(auto j:m[root]){
            if(!vis[j]){
                int temp=dfs(m,k-1,j,vis,ans);
                if(temp!=-1) ans[j->val]=true;
            }
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        if(root==NULL) return res;
        if(K==0){
            res.push_back(target->val);
            return res;
        }
        unordered_map<TreeNode*,vector<TreeNode*>> m;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* f=q.front();
                q.pop();
                if(f->left){
                    q.push(f->left);
                    m[f->left].push_back(f);
                    m[f].push_back(f->left);
                }if(f->right){
                    q.push(f->right);
                    m[f->right].push_back(f);
                    m[f].push_back(f->right);
                }
            }
        }
        if(K==1){
            for(auto j:m[target]){
                res.push_back(j->val);
            }
            return res;
        }
        unordered_map<int,bool> ans;
        unordered_map<TreeNode*,bool> vis;
        vis[target]=true;
        for( auto j:m[target]){
            if(vis.find(j)==vis.end() || vis[j]!=true){
                int temp=dfs(m,K-1,j,vis,ans);
            }
        }
        for(auto j:ans){
            if(j.first!=target->val) res.push_back(j.first);
        }
        return res;
    }
};




/* ALGO 2 */
class Solution {
public:
    vector<int> ans;   
    map<TreeNode*, TreeNode*> parent;  // son=>parent  
    set<TreeNode*> visit;    //record visied node
    
    void findParent(TreeNode* node){
        if(!node ) return;
        if( node->left ){
            parent[node->left] = node;
            findParent(node->left);
        }
        if( node->right){
            parent[node->right] = node;
            findParent(node->right);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if( !root ) return {};
        
        findParent(root);
        dfs(target, K );
        return ans;
    }
    void dfs( TreeNode* node, int K){
        if( visit.find(node) != visit.end() )
            return;
        visit.insert(node);
        if( K == 0 ){
            ans.push_back(node->val);
            return;
        }
        if( node->left ){
            dfs(node->left, K-1);
        }
        if( node->right){
            dfs(node->right, K-1);
        }
        TreeNode* p = parent[node];
        if( p )
            dfs(p, K-1);
    }
};
