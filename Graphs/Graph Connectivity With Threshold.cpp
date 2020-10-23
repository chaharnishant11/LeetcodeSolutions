class UnionFind {
    vector<int> parent, size;
public:
    UnionFind(int n) {
        parent.resize(n); size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i; size[i] = 1;
        }
    }
    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]); // Path compression
    }
    bool Union(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (size[pu] > size[pv]) { // Union by larger size
            size[pu] += size[pv];
            parent[pv] = pu;
        } else {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        return true;
    }
};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        UnionFind uf(n+1);
        for (int i = threshold+1; i <= n; i++) {
            for (int j = 2; j <= n; j ++) {
                long long a= i*j;
                if(a>n) break;
                uf.Union(i, a);
            }
        }
                
        vector<bool> ans;
        for (auto& q : queries) {
            int pa = uf.find(q[0]);
            int pb = uf.find(q[1]);
            ans.push_back(pa == pb);
        }
        return ans;
    }
};
