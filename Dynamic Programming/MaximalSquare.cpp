class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(n==0) return 0;
        int m=matrix[0].size();
        if(n==0 || m==0) return 0;
        int dp[n][m];
        if(matrix[0][0]=='1') dp[0][0]=1;
        else dp[0][0]=0;
        for(int i=1;i<n;i++){
            if(matrix[i][0]=='1'){
                dp[i][0]=1;
            }else dp[i][0]=0;
        }
        for(int j=1;j<m;j++){
            if(matrix[0][j]=='1')
                dp[0][j]=1;
            else dp[0][j]=0;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }else{
                    dp[i][j]=0;
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,dp[i][j]);
            }
        }
        return pow(ans,2);
    }
};