class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        if(n==0) return {{}};
        int m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX-100000));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                }else{
                    if(i>0){
                        ans[i][j]=min(ans[i][j],ans[i-1][j]+1);
                    }
                    if(j>0){
                        ans[i][j]=min(ans[i][j],ans[i][j-1]+1);
                    }
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i<n-1){
                    ans[i][j]=min(ans[i][j],ans[i+1][j]+1);
                }
                if(j<m-1){
                    ans[i][j]=min(ans[i][j],ans[i][j+1]+1);
                }
            }
        }
        return ans;
    }
};