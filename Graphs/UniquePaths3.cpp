class Solution {
public:
    int ans=0;
    void dfs(int i,int j,int n,int m,vector<vector<int>>& grid,int zero,int c){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==-1) return;
        if(grid[i][j]==2){
            if(zero+1==c)ans++;
            return;
        }
        grid[i][j]=-1;
        dfs(i+1,j,n,m,grid,zero,c+1);
        dfs(i,j+1,n,m,grid,zero,c+1);
        dfs(i-1,j,n,m,grid,zero,c+1);
        dfs(i,j-1,n,m,grid,zero,c+1);
        grid[i][j]=0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0) return 0;
        int m=grid[0].size();
        int r,c,zero=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    r=i;
                    c=j;
                }if(grid[i][j]==0){
                    zero++;
                }
            }
        }
        dfs(r,c,n,m,grid,zero,0);
        return ans;
    }
};