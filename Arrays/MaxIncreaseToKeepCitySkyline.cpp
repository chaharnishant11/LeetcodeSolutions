class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0) return 0;
        int m=grid[0].size();
        vector<int> row(n,0);
        vector<int> col(m,0);
        for(int i=0;i<n;i++){
            int temp=INT_MIN;
            for(int j=0;j<m;j++){
                temp=max(temp,grid[i][j]);
            }
            row[i]=temp;
        }
        for(int j=0;j<m;j++){
            int temp=INT_MIN;
            for(int i=0;i<n;i++){
                temp=max(temp,grid[i][j]);
            }
            col[j]=temp;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int temp=min(row[i],col[j]);
                ans+=temp-grid[i][j];
            }
        }
        return ans;
    }
};