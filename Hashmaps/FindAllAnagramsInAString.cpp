class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()==0) return {};
        if(s.size()<p.size()) return {};
        vector<int> sc(26,0),pc(26,0),ans;
        for(int i=0;i<p.size();i++){
            sc[s[i]-'a']++;
            pc[p[i]-'a']++;
        }
        if(sc==pc) ans.push_back(0);
        for(int i=p.size();i<s.size();i++){
            sc[s[i]-'a']++;
            sc[s[i-p.size()]-'a']--;
            if(sc==pc) ans.push_back(i-p.size()+1);
        }
        return ans;
    }
};