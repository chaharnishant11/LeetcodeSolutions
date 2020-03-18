class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> g[n];
        for(int i=0;i<n;i++){
            vector<int> v;
            g[i]=v;
        }
        for(int i=0;i<p.size();i++){
            g[p[i][1]].push_back(p[i][0]);
        }
        int id[n];
        for(int i=0;i<n;i++){
            id[i]=0;
        }
        for(int i=0;i<n;i++){
            for(auto j:g[i]) id[j]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++) if(id[i]==0) q.push(i);
        vector<int> ans;
        int c=0;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            ans.push_back(f);
            c++;
            for( auto j:g[f]){
                id[j]--;
                if(id[j]==0) q.push(j);
            }
        }
        vector<int> null;
        if(c!=n) return null;
        return ans;
    }
};