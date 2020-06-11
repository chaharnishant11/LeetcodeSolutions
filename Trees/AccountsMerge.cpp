class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,set<string>> m;
        for(auto a:accounts){
            for(int i=1;i<a.size();i++){
                m[a[i]].insert(a[1]);
                m[a[1]].insert(a[i]);
            }
        }
        
        unordered_set<string> s;
        vector<vector<string>> res;
        for(auto a:accounts){
            if(s.find(a[1])==s.end()){
                vector<string> ans;
                dfs(m,s,a[1],ans);
                sort(ans.begin(),ans.end());
                ans.insert(ans.begin(),a[0]);
                res.push_back(ans);
            }
        }
        return res;
    }
    
    void dfs(unordered_map<string,set<string>>& m,unordered_set<string>& vis,string a,vector<string>& ans){
        ans.push_back(a);
        vis.insert(a);
        for(auto i:m[a]){
            if(vis.find(i)==vis.end()){
                dfs(m,vis,i,ans);
            }
        }
    }
};