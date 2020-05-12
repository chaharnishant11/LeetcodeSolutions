class Solution {
public:
    string helper(string s,int i){
        if(i==s.size()) return "";
        int j=i;
        while(i<s.size() && s[i]>='0' && s[i]<='9'){
            i++;
        } 
        int x=1;
        if(i-j>0){
            x=stoi(s.substr(j,i-j));
        }
        j=i;
        string ans="";
        if(s[i]=='['){
            i++;
        }
        string temp="";
        while(i<s.size() && ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))){
            temp+=s[i];
            i++;
        }
        if(s[i]>'0' && s[i]<='9'){
            temp+=helper(s,i);
        }
        for(int k=0;k<x;k++){
            ans+=temp;
        }
        if(s[i]==']'){
            ans+=helper(s,i+1);
        }
        return ans;
    }
    string decodeString(string s) {
        string ans="";
        int ob=0;
        int cb=0;
        int j=0;
        for(int i=0;i<s.size() && j<s.size();i++){
            if(s[i]=='[') ob++;
            if(s[i]==']') cb++;
            if(ob==cb && ob!=0){
                ans+=helper(s.substr(j,i-j+1),0);
                j=i+1;
                ob=0;
                cb=0;
            }   
        }
        while(j<s.size()){
            ans+=s[j++];
        }
        return ans;
    }
};