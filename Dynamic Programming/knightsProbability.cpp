class Solution {
public:
    bool isSafe(int n,int r,int c){
        if(r<0 || c<0 || r>=n || c>=n) return false;
        return true;
    }
    double knightProbability(int n, int K, int r, int c) {
        double dp[n][n][K+1];
        int dr[8]={2, 2, 1, 1, -1, -1, -2, -2};
        int dc[8]={1, -1, 2, -2, 2, -2, 1, -1};
        memset(dp,0,sizeof(dp));
        dp[r][c][0]=1;
        for(int s=1;s<=K;s++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int k=0;k<8;k++){
                        int x=i+dr[k];
                        int y=j+dc[k];
                        if(isSafe(n,x,y)){
                            dp[x][y][s]+=dp[i][j][s-1]/8.0;
                        }
                    }
                }
            }
        }
        double ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans+=dp[i][j][K];
            }
        }
        return ans;
    }
};