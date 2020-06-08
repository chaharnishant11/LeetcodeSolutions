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
    long ans=INT_MIN;
    vector<int> s;
    #define MOD 1000000007
    long total;
    long sum1(TreeNode* root){
        if(root==NULL) return 0;
        int temp = root->val+sum1(root->left)+sum1(root->right);
        s.push_back(temp);
        return temp;
    }
    int maxProduct(TreeNode* root) {
        total=sum1(root);
        long ans=0;
        for(auto j:s){
            ans=max(ans,(total-j)*j);
        }
        return ans%MOD;
    }
};