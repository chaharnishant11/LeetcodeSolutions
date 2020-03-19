class Solution {
public:
    double dfs(map<string,unordered_map<string,double>> m,string f,string s,set<string>& vis){
        if(m[f].find(s) != m[f].end()) return m[f][s];
        for(auto j:m[f]){
            if(vis.find(j.first)==vis.end()){
                vis.insert(j.first);
                double temp=dfs(m,j.first,s,vis);
                if(temp) return temp*j.second;
            }
        }
        return 0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        map<string,unordered_map<string,double>> m;
        for(int i=0;i<e.size();i++){
            string first=e[i][0];
            string second=e[i][1];
            double value=v[i];
            m[first].insert(make_pair(second,value));
            m[second].insert(make_pair(first,1/value));
        }
        vector<double> ans;
        for(int i=0;i<q.size();i++){
            string first=q[i][0];
            string second=q[i][1];
            set<string> vis;
            double temp=dfs(m,first,second,vis);
            if(temp)ans.push_back(temp);
            else ans.push_back(-1.0);
        }
        return ans;
    }
};