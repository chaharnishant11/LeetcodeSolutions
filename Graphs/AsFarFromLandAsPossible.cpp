class Solution {
public:
    int maxDistance(vector<vector<int>>& g) {
        int steps=0;
        queue<pair<int, int>> q;
        for (auto i = 0; i < g.size(); ++i)
            for (auto j = 0; j < g[i].size(); ++j)
              if (g[i][j] == 1)
                q.push({ i - 1, j }), q.push({ i + 1, j }), q.push({ i, j - 1 }), q.push({ i, j + 1 });
        while (!q.empty()) {
            ++steps;
            int n=q.size();
            for(int k=0;k<n;k++) {
              int i = q.front().first, j = q.front().second;
              q.pop();
              if (i >= 0 && j >= 0 && i < g.size() && j < g[i].size() && g[i][j] == 0) {
                g[i][j] = steps;
                q.push({ i - 1, j }), q.push({ i + 1, j }), q.push({ i, j - 1 }), q.push({ i, j + 1 });
              }
            }
        }
        return steps == 1 ? -1 : steps - 1;
    }
};