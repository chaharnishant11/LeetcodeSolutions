class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int m=B.size();
        if(m<n) return findMedianSortedArrays(B,A);
        int l=0;
        int r=n;
        while(l<=r){
            int px=(r-l)/2+l;
            int py=(n+m+1)/2-px;
            
            int maxlx=(px==0)?INT_MIN:A[px-1];
            int minrx=(px==n)?INT_MAX:A[px];
            
            int maxly=(py==0)?INT_MIN:B[py-1];
            int minry=(py==m)?INT_MAX:B[py];
            
            if(maxlx<=minry && maxly<=minrx){
                if((n+m)%2==0){
                    return double(max(maxlx,maxly)+min(minrx,minry))/2.0;
                }else{
                    return double(max(maxlx,maxly));
                }
            }else if(maxlx>minry){
                r=px-1;
            }else{
                l=px+1;
            }
        }
        return 0.0;
    }
};