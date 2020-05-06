class Solution {
public:
    int dp[100001] = {};
    int helper(string &s, int i, int k) {
        if(i==s.size())
            return 1;
        if(s[i]=='0')
            return 0;
        if(!dp[i]){
            long long num = 0;
            for (long j = i; j < s.size(); ++j) {
                num=num*10+(s[j]-'0');
                if(num>k)
                    break;
                dp[i]=(dp[i]+helper(s,j+1,k))%1000000007;
            }
        }
        return dp[i];
    }
    int numberOfArrays(string s, int k) {
        return helper(s, 0, k);
    }
};