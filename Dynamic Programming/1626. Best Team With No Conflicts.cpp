class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> v;
        for(int i=0; i<ages.size(); i++) v.push_back({ages[i], scores[i]});
        sort(v.begin(), v.end());
        int n= v.size();
        vector<int> dp(n);
        int ans= 0;
        for(int i=0; i<n; i++) {
            dp[i]= v[i].second;
            for(int j=i-1; j>=0; j--) {
                if(v[j].first<v[i].first && v[j].second<=v[i].second) dp[i]= max(dp[i], v[i].second+dp[j]);
                else if(v[j].first==v[i].first) dp[i]= max(dp[i], v[i].second+dp[j]);
            }
            ans= max(ans, dp[i]);
        }
        return ans;
    }
};
