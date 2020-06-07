class Solution {
public:
    int dp[51][51][51];
    #define MOD 1000000007
    int dfs(int i,int j,int m,int n,int N){
        if(i<0 || i>=m || j<0 || j>=n){
            return 1;
        }
        if(dp[N][i][j]!=-1) return dp[N][i][j];
        if(N==0) return 0;
        int temp=0;
        temp=(temp%MOD+dfs(i+1,j,m,n,N-1)%MOD)%MOD;
        temp=(temp%MOD+dfs(i,j+1,m,n,N-1)%MOD)%MOD;
        temp=(temp%MOD+dfs(i-1,j,m,n,N-1)%MOD)%MOD;
        temp=(temp%MOD+dfs(i,j-1,m,n,N-1)%MOD)%MOD;
        dp[N][i][j]=temp%MOD;
        return dp[N][i][j];
    }
    
    int findPaths(int m, int n, int N, int i, int j) {
        for(int i=0;i<=N;i++)
            for(int j=0;j<m;j++)
                for(int k=0;k<n;k++) dp[i][j][k]=-1;
        int ans=dfs(i,j,m,n,N);
        return ans;
    }
};