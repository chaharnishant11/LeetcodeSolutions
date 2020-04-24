class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> g[n + 1];
        for (auto t : times) {
            g[t[0]].push_back(make_pair(t[1], t[2]));
        }
        const int inf = INT_MAX;
        vector<int> dist(n + 1, inf);
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push(make_pair(0, k));
        int u, v, w;
        while (!pq.empty()) {
            pair<int,int> p = pq.top(); 
            pq.pop();
            u = p.second;
            for (auto to : g[u]) {
                v = to.first, w = to.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == inf ? -1 : ans;
    }
};