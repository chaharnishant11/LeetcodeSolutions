int Solution::solve(vector<int> &A, int B) {
    int h=0;
    for(int i=0;i<A.size();i++){
        h=max(h,A[i]);
    }
    int l=0;
    int ans=l;
    while(l<=h){
        int mid=(h-l)/2+l;
        long long int temp=0;
        for(int i=0;i<A.size();i++){
            if(A[i]>mid){
                temp+=A[i]-mid;
            }
        }
        if(temp>=B){
            ans=max(ans,mid);
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    return ans;
}
