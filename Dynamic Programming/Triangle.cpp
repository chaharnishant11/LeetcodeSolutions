class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        if(t.size()==0) return 0;
        for(int i=1;i<t.size();i++){
            for(int j=0;j<t[i].size();j++){
                int temp=INT_MAX;
                int m=t[i-1].size();
                if(j-1>=0 && j-1<m){
                    temp=min(temp,t[i][j]+t[i-1][j-1]);
                }
                if(j>=0 && j<m){
                    temp=min(temp,t[i][j]+t[i-1][j]);
                }
                t[i][j]=temp;
            }
        }
        int n=t.size();
        int ans=INT_MAX;
        for(int i=0;i<t[n-1].size();i++){
            ans=min(ans,t[n-1][i]);
        }
        return ans;
    }
};