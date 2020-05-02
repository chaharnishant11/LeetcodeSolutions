class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int x[4]={0,0,1,-1};
        int y[4]={1,-1,0,0};
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        int ans=4*count;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int l=i+x[k];
                        int m=j+y[k];
                        if(m>=0 && m<grid[i].size() && l>=0 && l<grid.size() && grid[l][m]==1) ans--;
                    }
                }
            }
        }
        return ans;
    }
};