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
    TreeNode* helper(vector<int>& po, vector<int>& in,int ps,int pe,int is,int ie){
        if(is>ie || is<0 || ps>pe || ps<0) return NULL;
        TreeNode* root=new TreeNode(po[pe]);
        int index=-1;
        for(int i=is;i<=ie;i++){
            if(in[i]==po[pe]) index=i;
        }
        root->left=helper(po,in,ps,ps+index-1-is,is,index-1);
        root->right=helper(po,in,ps+index-is,pe-1,index+1,ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        return helper(postorder,inorder,0,n-1,0,n-1);
    }
};
 