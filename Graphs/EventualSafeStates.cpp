class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visit(n, -1), res;
        for (int i = 0; i < n; ++i) {
            if (dfs(i, graph, visit)) {
                res.push_back(i);
            }
        }
        return res;
    }
    bool dfs(int i, vector<vector<int>>& g, vector<int> &vis) {
        if (vis[i] != -1) {
            return vis[i];
        }
        vis[i] = 0;
        for(int j=0;j<g[i].size();j++){
            if(!dfs(g[i][j],g,vis)) return vis[g[i][j]];
        }
        vis[i]=1;
        return true;
    }
};