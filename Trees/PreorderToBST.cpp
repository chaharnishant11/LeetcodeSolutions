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
    TreeNode* helper(vector<int> pre,int s,int e){
        if(s>e) return NULL;
        TreeNode* root=new TreeNode(pre[s]);
        int index=-1;
        for(int i=s+1;i<=e;i++){
            if(pre[s]<pre[i]){
                index=i;
                break;
            }
        }
        if(index==-1){
            root->left=helper(pre,s+1,e);
        }else{
            root->left=helper(pre,s+1,index-1);
            root->right=helper(pre,index,e);
        }
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder,0,preorder.size()-1);
    }
};