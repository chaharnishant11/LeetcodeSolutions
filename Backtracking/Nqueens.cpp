class Solution {
public:
    bool safe(vector<string>& b,int n,int r,int c){
        for (int i = 0; i != r; ++i)
            if (b[i][c] == 'Q')
                return false;
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; --i, --j)
            if (b[i][j] == 'Q')
                return false;
        for (int i = r - 1, j = c + 1; i >= 0 && j < n; --i, ++j)
            if (b[i][j] == 'Q')
                return false;
        return true;
    }
    void helper(vector<string>& b,int n,int row,vector<vector<string>>& ans){
        if(row==n){
            ans.push_back(b);
            return;
        }
        for(int i=0;i<n;i++){
            if(safe(b,n,row,i)){
                b[row][i]='Q';
                helper(b,n,row+1,ans);
                b[row][i]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string x="";
        for(int i=0;i<n;i++) x+='.';
        vector<string> b(n,x);
        helper(b,n,0,ans);
        return ans;
    }
};