class Solution {
public:
    double ans=0;
    bool dfs(vector<int> g[],int n,int t,int tar,double prob,int i,vector<bool>& vis){
        if(t==0 || (g[i].size()==1 && i!=0)){
            if(i==tar){
                ans=prob;
                return true;
            }
            return false;
        }
        vis[i]=true;
        double x=g[i].size()-(i!=0);
        double temp=1/x;
        for(auto j:g[i]){
            if(!vis[j]){
                bool subans=dfs(g,n,t-1,tar,prob*temp,j,vis);
                if(subans){
                    return true;
                } 
            }
        }
        return false;
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<int> g[n];
        if(n==1 && edges.size()==0) return 1;
        for(int i=0;i<n;i++){
            vector<int> t;
            g[i]=t;
        }
        for(auto i:edges){
            g[i[0]-1].push_back(i[1]-1);
            g[i[1]-1].push_back(i[0]-1);
        }
        target--;
        vector<bool> vis(n,false);
        bool found = dfs(g,n,t,target,1,0,vis);
        if(found) return ans;
        return 0.0;
    }
};