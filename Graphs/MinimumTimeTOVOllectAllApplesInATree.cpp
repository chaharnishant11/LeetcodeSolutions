class Solution {
public:
    int ans=0;
    bool helper(int n,vector<int> g[],vector<bool>& a,vector<bool>& vis,int i){
        bool val=false;
        vis[i]=true;
        for(auto j:g[i]){
            if(!vis[j]){
                bool temp=helper(n,g,a,vis,j);
                if(temp){
                    ans+=2;
                }
                val=val||temp;
            }
        }
        val=val||a[i];
        return val;
    }
    int minTime(int n, vector<vector<int>>& e, vector<bool>& hasApple) {
        vector<int> g[n];
        for(int i=0;i<n;i++){
            vector<int> temp;
            g[i]=temp;
        }
        for(int i=0;i<e.size();i++){
           g[e[i][0]].push_back(e[i][1]);
        }
        vector<bool> vis(n,false); 
        bool temp=helper(n,g,hasApple,vis,0);
        return ans;
    }
};