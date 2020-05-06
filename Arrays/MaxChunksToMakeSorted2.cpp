class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int lmax[n];
        int rmin[n];
        lmax[0]=arr[0];
        for(int i=1;i<n;i++){
            lmax[i]=max(lmax[i-1],arr[i]);
        }
        rmin[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            rmin[i]=min(rmin[i+1],arr[i]);
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(lmax[i]<=rmin[i+1]) ans++;
        }
        return ans+1;
    }
};