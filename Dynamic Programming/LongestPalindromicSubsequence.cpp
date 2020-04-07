//ALOG-1
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==0) return "";
        int i = 0, j = 0;
        int n = s.size();
        bool dp[n][n];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j]=false;
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
         for(int l=2;l<=n;l++){
             for(int i=0;i<n-l+1;i++){
                 int j=i+l-1;
                 if(l==2 && s[i]==s[j]) dp[i][j]=true;
                 else dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
             }
         }   
        int m=0;
        string ans="";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j] && j-i+1>m){
                    m=j-i+1;
                    ans=s.substr(i,m);
                }
            }
        }
        return ans;
    }
};