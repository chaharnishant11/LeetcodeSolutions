class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> m;
    void dfs(string src,vector<string>& ans){
        while(!m[src].empty()){
            string des=m[src].top();
            m[src].pop();
            dfs(des,ans);
        }
        ans.push_back(src);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i=0;i<tickets.size();i++){
            m[tickets[i][0]].push(tickets[i][1]);
        }
        vector<string> ans;
        dfs("JFK",ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};