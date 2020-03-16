class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                }
            }
        }
        //bool vis[grid.size()][grid[0].size()]={false};
        q.push(make_pair(-1,-1));
        int ans=0;
        int x[4]={0,0,1,-1};
        int y[4]={1,-1,0,0};
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(i==-1 && j==-1){
                if(!q.empty()) q.push(make_pair(-1,-1));
                ans++;
                continue;
            }
            for(int l=0;l<4;l++){
                int p=i+x[l];
                int r=j+y[l];
                if(p>=0 && p<grid.size() && r>=0 && r<grid[0].size() && grid[p][r]==1){
                    grid[p][r]=2;
                    q.push(make_pair(p,r));
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans-1;
    }
};