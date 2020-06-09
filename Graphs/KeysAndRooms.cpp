class Solution {
public:
    
    void dfs(vector<vector<int>>& rooms,vector<bool>& vis,int i){
        vis[i]=true;
        for(auto j:rooms[i]){
            if(!vis[j]) dfs(rooms,vis,j);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        if(n==0) return false;
        vector<bool> vis(n,false);
        dfs(rooms,vis,0);
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};