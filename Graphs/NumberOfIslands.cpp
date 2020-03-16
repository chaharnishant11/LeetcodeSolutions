class Solution {
public:
    void dfs(vector<vector<char>>& g,int i,int j){
        g[i][j]='0';
        int x[]={0,0,1,-1};
        int y[]={1,-1,0,0};
        for(int k=0;k<4;k++){
            int l=i+x[k];
            int m=j+y[k];
            if(l>=0 && l<g.size() && m>=0 && m<g[0].size() && g[l][m]=='1'){
                g[i][j]='0';
                dfs(g,l,m);
            }
           
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    //cout << i << " " << j << endl;
                    ans++;
                }
            }
        }
        return ans;
    }
};