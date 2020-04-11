class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n=A.size();
        if(n==0) return 0;
        int dp[n][n];
        for(int i=0;i<n;i++){
            dp[0][i]=A[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j+1])+A[i][j];
                }else if(j==n-1){
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+A[i][j];
                }else{
                    dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]))+A[i][j];
                }
            }
        }
        int ans=dp[n-1][0];
        for(int i=1;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};