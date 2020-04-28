class Solution {
public:
    bool helper(vector<vector<int>>& g,int r,int c){
        int count[20]={0};
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                count[g[r+i][c+j]]++;
        for(int i=1;i<=9;i++) 
            if(count[i]!=1) return false;
        int sum=g[r][c]+g[r+1][c+1]+g[r+2][c+2];
        if(g[r][c+2]+g[r+1][c+1]+g[r+2][c]!=sum) return false;
        for(int i=0;i<3;i++)
            if(g[r+i][c]+g[r+i][c+1]+g[r+i][c+2]!=sum) return false;
        for(int i=0;i<3;i++)
            if(g[r][c+i]+g[r+1][c+i]+g[r+2][c+i]!=sum) return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        if(n<3 || m<3 ) return ans;
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                if(helper(grid,i,j)) ans++;
            }
        }
        return ans;
    }
};
