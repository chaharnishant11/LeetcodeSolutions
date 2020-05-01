class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1]+nums[i];
        }
        int ans=dp[0];
        for(int i=0;i<n;i++){
            ans=min(dp[i],ans);
        }
        if(ans<0){
            ans=-1*ans;
            ans=ans+1;
            int x=ans;
            for(int i=0;i<n;i++){
                ans+=nums[i];
                if(ans<=0){
                    x+=-1*ans;
                    ans=x;
                }
            }
            return x;
        }else return 1;
    }
};