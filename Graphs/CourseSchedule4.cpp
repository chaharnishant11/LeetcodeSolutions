// Floyd Warshal

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> connect(n, vector<bool>(n, false));
        for (auto&& pre : prerequisites)
            connect[pre[0]][pre[1]] = true;
        
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    connect[i][j] = connect[i][j] || (connect[i][k] && connect[k][j]);
        
        vector<bool> res;
        for (auto&& query : queries) 
            res.push_back(connect[query[0]][query[1]]);
        
        return res;
    }
};