static auto fast=[]{ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    int dfs(vector<int> g[],vector<int>& q, int i,vector<int>& ret){
        if(ret[i]!=-1) return ret[i];
        int ans=i;
        int val=q[i];
        for(auto j:g[i]){
            int temp=dfs(g,q,j,ret);
            if(q[temp]<val){
                ans=temp;
                val=q[temp];
            }
        }
        ret[i]=ans;
        return ans;
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int> g[n];
        for(int i=0;i<n;i++){
            vector<int> t;
            g[i]=t;
        }
        for(int i=0;i<richer.size();i++){
            g[richer[i][1]].push_back(richer[i][0]);
        }
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            if(ans[i]==-1){
                int temp=dfs(g,quiet,i,ans);
            }
        }
        return ans;
    }
};