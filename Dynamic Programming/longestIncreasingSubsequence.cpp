// o(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums){
        int n=nums.size();
        if(n<=0) return n;
        vector<int> dp(n,1);
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};

// O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums){
        int n=nums.size();
        if(n<=0) return n;
        vector<int> dp(n,0);
        int len = 0 ;
        for(auto num :nums){
            int i=lower_bound(dp.begin(),dp.begin()+len,num)-dp.begin();
            if(i<0){
                i=-(i+1);
            }
            dp[i]=num;
            if(i==len){
                len++;
            }
        }
        return len;
    }
};