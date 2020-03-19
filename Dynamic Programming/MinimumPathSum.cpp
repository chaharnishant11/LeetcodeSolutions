class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int g[n][m];
        g[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
            g[i][0]=g[i-1][0]+grid[i][0];
        }
        for(int i=1;i<m;i++){
            g[0][i]=grid[0][i]+g[0][i-1];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                g[i][j]=min(g[i-1][j],g[i][j-1])+grid[i][j];
            }
        }
        return g[n-1][m-1];
    }
};