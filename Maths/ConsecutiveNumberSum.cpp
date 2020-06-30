class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans=0;
        for(int n=2;n*(n+1)/2<=N;n++){
            if((N-((n*(n+1))/2))%n==0) ans++;
        }
        return ans+1;
    }
};