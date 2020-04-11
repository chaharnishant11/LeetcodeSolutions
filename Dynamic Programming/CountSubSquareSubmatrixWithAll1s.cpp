class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        if(n==0 || m==0) return 0;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j]==1){
                    mat[i][j]=min(mat[i-1][j-1],min(mat[i-1][j],mat[i][j-1]))+1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]!=0){
                    ans=ans+mat[i][j];
                }
            }
        }
        return ans;
    }
};