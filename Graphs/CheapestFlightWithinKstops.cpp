// Dijkstra
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int K) {
        vector<pair<int,int>> g[n];
        for(int i=0;i<f.size();i++){
            g[f[i][0]].push_back({f[i][1],f[i][2]});
        }
         priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push({0,K+1,src});
        while(!pq.empty()){
            tuple<int,int,int> p=pq.top();pq.pop();
            int u=get<2>(p);
            int stops=get<1>(p);
            int price=get<0>(p);
            if(u==dst) return price;
            if(stops>0){
                for(auto i:g[u]){
                    int v=i.first,w=i.second;
                    pq.push({price+w,stops-1,v});
                }
            }
        }
        return -1;
    }
};

//DFS
static auto fast=[]{ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int s, int d, int K) {
       unordered_map<int, vector<pair<int,int>>> g;
       for (const auto& e : flights)
            g[e[0]].emplace_back(e[1], e[2]);        
        int ans = INT_MAX;
        vector<int> visited(n,0);
        dfs(s, d, K + 1, 0, visited, ans, g);
        return ans == INT_MAX ? - 1 : ans;
    }
    
    void dfs(int s, int d, int k, int cost, vector<int>& visited, int& ans, unordered_map<int, vector<pair<int,int>>>& g ) {
        if (s == d) { ans = cost; return; }
        if (k == 0) return; 
        visited[s]=1;
        for (const auto& x : g[s]) {
          if (visited[x.first]==0){
              if (cost + x.second > ans) continue; // IMPORTANT!!! prunning 
     
              dfs(x.first, d, k - 1, cost + x.second, visited, ans, g); 
             
          }
        }
         visited[s] = 0;
  }
};
