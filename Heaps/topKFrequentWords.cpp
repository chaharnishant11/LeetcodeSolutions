class Solution {
public:
    struct Compare { 
        bool operator()(pair<int,string> const& a,pair<int,string> const& b){
            if(a.first==b.first) return a.second<b.second;
            return a.first>b.first; 
        } 
    }; 
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,Compare> q;
        for(auto i:m){
            q.push({i.second,i.first});
            if(q.size()>k){
                q.pop();
            }
        }
        vector<string> ans;
        while(!q.empty()){
            ans.insert(ans.begin(),q.top().second);
            q.pop();
        }
        return ans;
    }
};