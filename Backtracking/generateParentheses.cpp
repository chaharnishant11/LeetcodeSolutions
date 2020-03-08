class Solution {
public:
    void helper(vector<string> &ans, string a, int n, int m){
        if(n==0 && m==0){
            ans.push_back(a);
            return;
        }
        if(m>0) helper(ans,a+')',n,m-1);
        if(n>0) helper(ans,a+'(',n-1,m+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n==0){
            return ans;
        }
        helper(ans,"",n,0);
        return ans;
    }
};
