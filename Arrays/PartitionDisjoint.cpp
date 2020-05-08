class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int n=A.size();
        int lmax[n];
        int rmin[n];
        lmax[0]=A[0];
        rmin[n-1]=A[n-1];
        for(int i=1;i<n;i++){
            lmax[i]=max(lmax[i-1],A[i]);
        }
        for(int i=n-2;i>=0;i--){
            rmin[i]=min(rmin[i+1],A[i]);
        }
        int ans=n;
        for(int i=0;i<n-1;i++){
            if(lmax[i]<=rmin[i+1]){
                //cout << lmax[i] << " " << rmin[i+1] <<  endl;
                return i+1;
            }
        }
        return ans+1;
    }
};