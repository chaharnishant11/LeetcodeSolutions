class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int l=1;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j=l+i-1;
                for(int k=i;k<=j;k++){
                    int left=(k==i)?0:dp[i][k-1];
                    int right=(k==j)?0:dp[k+1][j];
                    int l=(i==0)?1:nums[i-1];
                    int r=(j==n-1)?1:nums[j+1];
                    int temp=left+(l*nums[k]*r)+right;
                    //cout << i << " " << j << " " << k << " " << left << " " << right << " "  <<l << " " << r << " " << temp << endl;
                    dp[i][j]=max(temp,dp[i][j]);
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++) cout << dp[i][j] << " ";
        //     cout << endl;
        // }
        return dp[0][n-1];
    }
};