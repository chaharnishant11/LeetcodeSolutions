class NumMatrix {
public:
    vector<vector<int>> sum;
    
    NumMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        if(n==0) return;
        int m=mat[0].size();
        if(m==0) return;
        for(int i=0;i<=n;i++){
            vector<int> temp;
            if(i==0){
                for(int j=0;j<=m;j++){
                    temp.push_back(0);
                }
            }else{
                for(int j=0;j<=m;j++){
                    if(j==0) temp.push_back(0);
                    else temp.push_back(mat[i-1][j-1]);
                }
            }
            sum.push_back(temp);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                sum[i][j]=sum[i-1][j]+sum[i][j-1]+mat[i-1][j-1]-sum[i-1][j-1];
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         cout << sum[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int s=sum[row2+1][col2+1]-sum[row1][col2+1]-sum[row2+1][col1]+sum[row1][col1];
        return s;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */