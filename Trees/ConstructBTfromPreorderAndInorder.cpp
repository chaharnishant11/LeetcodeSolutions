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
    TreeNode* helper(vector<int>& pr, vector<int>& in,int ps,int pe,int is,int ie){
        if(is>ie) return NULL;
        TreeNode* root=new TreeNode(pr[ps]);
        int index=-1;
        for(int i=is;i<=ie;i++){
            if(in[i]==pr[ps]) index=i;
        }
        root->left=helper(pr,in,ps+1,ps+index-is,is,index-1);
        root->right=helper(pr,in,ps+index-is+1,pe,index+1,ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return helper(preorder,inorder,0,n-1,0,n-1);
    }
};