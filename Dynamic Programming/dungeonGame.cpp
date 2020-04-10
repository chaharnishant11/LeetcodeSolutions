class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int n=d.size();
        int m=d[0].size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++) dp[i][j]=INT_MAX;
        }
        dp[n][m-1]=1;
        dp[n-1][m]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int help=min(dp[i+1][j],dp[i][j+1])-d[i][j];
                dp[i][j]=(help<=0)?1:help;
            }
        }
        return dp[0][0];
    }
};