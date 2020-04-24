class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int s=primes.size();
        int p[s];
        int dp[n];
        memset(p,0,sizeof(p));
        dp[0]=1;
        for(int i=1;i<n;i++){
            int element=INT_MAX;
            for(int j=0;j<s;j++){
                element=min(dp[p[j]]*primes[j],element);
            }
            dp[i]=element;
            for(int j=0;j<s;j++){
                if(dp[i]==dp[p[j]]*primes[j])p[j]++;
            }
        }
        //for(int i=0;i<n;i++) cout << dp[i] << " ";
        return dp[n-1];
    }
};