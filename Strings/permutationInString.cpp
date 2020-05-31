class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1c(26,0);
        vector<int> s2c(26,0);
        if(s2.size()<s1.size()) return false;
        for(int i=0;i<s1.size();i++){
            s1c[s1[i]-'a']++;
            s2c[s2[i]-'a']++;
        }
        if(s1c==s2c) return true;
        for(int i=s1.size();i<s2.size();i++){
            s2c[s2[i]-'a']++;
            s2c[s2[i-s1.size()]-'a']--;
            if(s1c==s2c) return true;
        }
        return false;
    }
};