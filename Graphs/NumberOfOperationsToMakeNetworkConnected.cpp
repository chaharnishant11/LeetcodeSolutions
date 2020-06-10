class Solution {
public:
    
    int find(int x,vector<int>& parent){
        if(parent[x]==-1) return x;
        int px=find(parent[x],parent);
        parent[x]=px;
        return px;
    }

    int makeConnected(int n, vector<vector<int>>& c) {
        int m=c.size();
        if(m<n-1) return -1;
        vector<int> parent(n,-1);
        for(int i=0;i<c.size();i++){
            int px=find(c[i][0],parent);
            int py=find(c[i][1],parent);
            if(px!=py) parent[px]=py;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(parent[i]==-1) count++;
        }
        return count-1;
    }
};