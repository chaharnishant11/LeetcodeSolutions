class Solution {
public:
    int allTimeProfit(vector<int> arr){
        int profit = 0;
        int localMin = arr[0];
        for(int i=1; i < arr.size();i++){
            if(arr[i-1] >= arr[i]){
                localMin = arr[i];
            }else{
                profit += arr[i] - localMin;
                localMin = arr[i];
            }

        }
        return profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()==0 || k==0) return 0;
        int n=prices.size();
        if(k>n/2){
            return allTimeProfit(prices);
        }
        int dp[k+1][n];
        for(int i=0;i<n;i++){
            dp[0][i]=0;
        }
        for(int i=0;i<k+1;i++){
            dp[i][0]=0;
        }
        int maxDiff=-prices[0];
        for(int i=1;i<k+1;i++){
            int maxDiff=-prices[0];
            for(int j=1;j<n;j++){
                dp[i][j]=max(dp[i][j-1],prices[j]+maxDiff);
                maxDiff=max(maxDiff,dp[i-1][j]-prices[j]);
            }
        }
        return dp[k][n-1];
    }
};