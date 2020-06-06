class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return {};
        int dp[n];
        int parent[n];
        sort(nums.begin(),nums.end());
        dp[0]=1;
        parent[0]=-1;
        int maxval=0;
        int index=-1;
        for(int i=0;i<n;i++){
            dp[i]=1;
            parent[i]=-1;
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        parent[i]=j;
                    }
                }
            }
            if(maxval<dp[i]){
                maxval=dp[i];
                index=i;
            }
        }
        vector<int> ans;
        while(index!=-1){
            ans.push_back(nums[index]);
            index=parent[index];
        }
        return ans;
    }
};