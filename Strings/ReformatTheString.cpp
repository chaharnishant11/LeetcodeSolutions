class Solution {
public:
    string reformat(string s) {
        vector<char> num;
        vector<char> alp;
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])){
                alp.push_back(s[i]);
            }else{
                num.push_back(s[i]);
            }
        }
        int n=num.size();
        int a=alp.size();
        if(abs(n-a)>1) return "";
        string ans="";
        int i=0,j=0;
        if(alp.size()>num.size()){
            ans+=alp[i];
            i++;
        }else if(alp.size()<num.size()){
            ans+=num[j];
            j++;
        }
        while(ans.size()<s.size()){
            if(alp.size()>num.size()){
                ans+=num[j++];
                ans+=alp[i++];
            }else{
                ans+=alp[i++];
                ans+=num[j++];
            }
        }
        return ans;
    }
};