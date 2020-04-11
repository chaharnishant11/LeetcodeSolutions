class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size()==0) return false;
        unordered_map<string,bool> m;
        for(int i=0;i<wordDict.size();i++){
            m[wordDict[i]]=true;
        }
        int n=s.size();
        int dp[n+1];
        for(int i=0;i<=n;i++) dp[i]=false;
        dp[0]=true;
        for(int i=1;i<=n;i++){
            if(!dp[i] && (m.find(s.substr(0,i))!=m.end())) dp[i]=true;
            if(dp[i]){
                if(i==n) return true;
                for(int j=i+1;j<=n;j++){
                    if(!dp[j] && (m.find(s.substr(i,j-i))!=m.end())) dp[j]=true;
                    if(j==n && dp[j]) return true;
                }
            }
            for(int i=0;i<=n;i++) cout << dp[i] << " ";
            cout << endl;
        }
        
        return false;
    }
};