class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        if(n==0) return false;
        int m=matrix[0].size();
        if(m==0) return false;
        int l=0;
        int h=n*m-1;
        while(l<=h){
            int mid=(h-l)/2+l;
            int mid_val=matrix[mid/m][mid%m];
            if(target==mid_val){
                return true;
            }else if(target>mid_val) l=mid+1;
            else h=mid-1;
        }
        return false;
    }
};