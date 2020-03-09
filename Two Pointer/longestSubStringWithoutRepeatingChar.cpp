class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int ans=0;
        int l=0;
        int r=0;
        map<char,bool> m;
        while(l<s.size() && r<s.size()){
            //cout << l << " " <<  r << endl;
            if(m.find(s[r])==m.end()){
                m[s[r]]=true;
                r++;
                ans=max(ans,r-l);
            }else{
                m.erase(s[l]);
                l++;
            }
        }
        return ans;
    }
};