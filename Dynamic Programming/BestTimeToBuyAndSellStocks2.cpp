class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int profit=0;
        int n=prices.size();
        int minima=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1]){
                profit+=prices[i]-minima;
            }
            minima=prices[i];
        }
        
        return profit;
    }
};