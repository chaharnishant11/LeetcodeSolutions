class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        int n = m.size();
        int l=m[0][0], h=m[n-1][n-1]+1;
        while(l<h){
            int mid=(h-l)/2+l;
            int ans=0;
            int j=n-1;
            for(int i=0;i<n;i++){
                while(j>=0 && m[i][j]>mid){
                    j--;
                }
                ans+=(j+1);
            }
            if(ans<k) l=mid+1;
            else h=mid;
        }
        return l;
    }
};