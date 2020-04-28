class Solution {
public:
    int helper(int n,int row,vector<int>& col,vector<int>& d45,vector<int>& d135){
        if(row==n){
            return 1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(col[i] && d45[i+row] && d135[n-1+i-row]){
                col[i]=d45[i+row]=d135[n-1+i-row]=0;
                ans+=helper(n,row+1,col,d45,d135);
                col[i]=d45[i+row]=d135[n-1+i-row]=1;
            }
        }
        return ans;
    }
    int totalNQueens(int n) {
        int ans=0;
        vector<int> col(n,1), diag45(2*n-1,1) , diag135(2*n-1,1);
        ans=helper(n,0,col,diag45,diag135);
        return ans;
    }
};