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

//Memoisation

class Solution {
public:
    int dp[502][502];
    vector<int> balloons;
    int helper(int l,int r,int n){
        if(dp[l][r]!=-1) return dp[l][r];
        int ans=0;
        for(int i=l+1;i<r;i++){
            int curr=helper(l,i,n)+helper(i,r,n);
            if(l==0 && r==n+1){
                curr=curr+balloons[i];
            }else{
                curr=curr+balloons[l]*balloons[i]*balloons[r];
            }
            ans=max(ans,curr);
        }
        dp[l][r]=ans;
        return ans;
    }
    
    int maxCoins(vector<int>& nums) {
        balloons=nums;
        memset(dp,-1,sizeof(dp));
        balloons.insert(balloons.begin(),1);
        balloons.push_back(1);
        int n=nums.size();
        int ans=helper(0,n+1,n);
        return ans;
    }
};