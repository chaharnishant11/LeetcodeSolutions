class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums){
            sum += num;
        }
        if ((sum & 1) == 1){
            return false;
        }
        sort(nums.begin(),nums.end());
        if(sum%2!=0) return false;
        sum /= 2;
        int n = nums.size();
        if(sum<nums[n-1]) return false;
        bool dp[sum+1];
        memset(dp,false,sizeof(dp));
        dp[0] = true;
        for (auto num : nums){
            for (int i = sum; i > 0; i--){
                if (i >= num) {
                    dp[i] = dp[i] || dp[i-num];
                }
            }
        }

        return dp[sum];
    }
};