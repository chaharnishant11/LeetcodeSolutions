class Solution {
public:
    bool canConstruct(string r, string mag) {
        int m[27]={0};
        for(int i=0;i<mag.size();i++){
            m[mag[i]-'a']++;
        }
        for(int i=0;i<r.size();i++){
            m[r[i]-'a']--;
        }
        for(int i=0;i<27;i++){
            if(m[i]<0) return false;
        }
        return true;
    }
};