static auto fast=[]{ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>> ans;
        if(v.size()==0)
            return ans;
        sort(v.begin(), v.end());
        ans.push_back(v[0]);
        for (int i = 1; i < v.size(); ++i){
            if (v[i][0] <= ans.back()[1]) 
                ans.back()[1] = max(v[i][1], ans.back()[1]);

            else
                ans.push_back(v[i]);
        }

        return ans;
    }
};