class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string,int> m;
        int n= s.length();
        n= n-10;
        for(int i=0; i<=n; i++) {
            string x= s.substr(i, 10);
            m[x]++;
        }
        for(auto i: m) if(i.second>1) ans.push_back(i.first);
        return ans;
    }
};
