class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        // TLE O(n*k)
        // int n=nums.size();
        // int dp[n];
        // memset(dp,0,sizeof(dp));
        // dp[0]=nums[0];
        // for(int i=1;i<n;i++){
        //     dp[i]=nums[i];
        //     for(int j=i-1;j>=0 && i-j<=k;j--){
        //         dp[i]=max(dp[i],nums[i]+dp[j]);
        //     }
        // }
        // int ans=INT_MIN;
        // for(int i=0;i<n;i++){
        //     ans=max(ans,dp[i]);
        // }
        // return ans;
        int n = nums.size();
        vector<int> dp(n);
        deque<int> q;
        
        dp[0]=nums[0];
        q.push_back(0);
        int ans=dp[0];
        
        for(int i=1;i<n;i++){   
            dp[i] = max(0,dp[q.front()]) + nums[i];
            ans=max(ans,dp[i]);
            
            while(!q.empty() && q.front()<=i-k)  //Similar to sliding window maximum problem
                q.pop_front();
            while(!q.empty() && dp[i]>=dp[q.back()])
                q.pop_back();
            q.push_back(i);
            
        }
        return ans;
    }
};