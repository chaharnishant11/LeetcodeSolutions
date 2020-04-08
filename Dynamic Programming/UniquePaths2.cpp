class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &og) {
       if(og[0][0]==1) return 0;
        int m=og.size();
        int n=og[0].size();
        long dp[m][n];
        dp[0][0]=1;
        for(int i=1;i<n;i++){
            if(og[0][i]!=1 && dp[0][i-1]!=0) dp[0][i]=1;
            else dp[0][i]=0;
        }
        for(int i=1;i<m;i++){
            if(og[i][0]!=1 && dp[i-1][0]!=0) dp[i][0]=1;
            else dp[i][0]=0;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(og[i][j]!=1 && (dp[i-1][j]!=0 || dp[i][j-1]!=0)){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }else dp[i][j]=0;
            }
        }
        return dp[m-1][n-1];
    }
};