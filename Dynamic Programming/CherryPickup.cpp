// O(n^3) space
class Solution {
public:
    int dp[50][50][50];
    vector<vector<int>> g;
    int helper(int r1,int c1,int c2,int N){
        int r2=r1+c1-c2;
        if(r1>=N || r2>=N || c1>=N || c2>=N || g[r1][c1]==-1 || g[r2][c2]==-1) return INT_MIN;
        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];
        if(r1==N-1 && c1==N-1) return g[r1][c1];
        int ans=g[r1][c1];
        if(c1!=c2) ans+=g[r2][c2];
        int temp=max(helper(r1,c1+1,c2+1,N),helper(r1+1,c1,c2+1,N));
        temp=max(helper(r1+1,c1,c2,N),temp);
        temp=max(temp,helper(r1,c1+1,c2,N));
        ans+=temp;
        dp[r1][c1][c2]=ans;
        return ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        g=grid;
        int N=grid.size();
        return max(0,helper(0,0,0,N));
    }
};