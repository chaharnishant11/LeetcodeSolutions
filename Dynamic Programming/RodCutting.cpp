void getAns(vector<int> &ans, vector<vector<int>> &dp, int i, int j, vector<int> p) {
    if(i+1==j) return;
    for(int l=i+1;l<j;l++){
        if(dp[i][l]+dp[l][j]-p[i]+p[j]==dp[i][j]){
            ans.push_back(p[l]);
            getAns(ans,dp,i,l,p);
            getAns(ans,dp,l,j,p);
            return;
        }
    }
}
vector<int> Solution::rodCut(int A, vector<int> &B) {
    vector<int> p;
    p.push_back(0);
    for (int b: B) p.push_back(b);
    p.push_back(A);
    sort(p.begin(), p.end());
    
    int n = p.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int l=1;l<=n;l++){
        for(int i=0;i+l-1<n;i++){
            int j=i+l-1;
            dp[i][j]=INT_MAX;
            for(int k=i+1;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]-p[i]+p[j]);
            }
        }
    }
    vector<int> ans;
    getAns(ans, dp, 0, n - 1, p);
    return ans;
    
}
