class Solution {
public:
    string sortString(string s) {
        int fre[27]={0};
        for(int i=0;i<s.size();i++){
            fre[(s[i]-'a')]++;
        }
        string ans="";
        for(int i=0;i<s.size() && ans.size()!=s.size();i++){
            for(int j=0;j<27;j++){
                if(fre[j]>0){
                    ans+=('a'+j);
                    fre[j]--;
                }
            }
            for(int j=26;j>=0;j--){
                if(fre[j]>0){
                    ans+=('a'+j);
                    fre[j]--;
                }
            }
        }
        return ans;
    }
};