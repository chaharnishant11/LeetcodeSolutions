class Solution {
public:
    int ans=INT_MAX;
    void dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs,vector<int>& curr,int cost){
        for(int i=0;i<curr.size();i++){
            if(curr[i]<0) return;
        }
        if(needs==curr){
            if(cost<ans){
                ans=cost;
                return;
            }
        }
        if(cost>=ans) return;
        for(int i=0;i<special.size();i++){
            bool possible = true;
            for(int j=0;j<special[i].size()-1;j++){
                if(special[i][j]+curr[j]>needs[j]){
                    possible =false;
                    break;
                }
            }
            if(possible){
                vector<int> temp=curr;
                for(int j=0;j<special[i].size()-1;j++){
                    curr[j]+=special[i][j];
                }
                int x=special[i].size();
                dfs(price,special,needs,curr,cost+special[i][x-1]);
                curr=temp;
            }
        }
        vector<int> temp=curr;
        int t=0;
        for(int i=0;i<curr.size();i++){
            t+=(needs[i]-curr[i])*price[i];
        }
        dfs(price,special,needs,needs,cost+t);
        curr=temp;
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n=price.size();
        if(n==0) return 0;
        vector<int> curr(n,0);
        dfs(price,special,needs,curr,0);
        return ans;
    }
};