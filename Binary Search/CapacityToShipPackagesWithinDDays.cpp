class Solution {
public:
    
    bool ship(vector<int>& w, int d, long long limit){
        long long sum=0;
        int c=0;
        for(int i=0;i<w.size();i++){
            if(sum+w[i]<=limit) sum+=w[i];
            else{
                c++;
                if(w[i]>limit) return false;
                sum=w[i];
            }
        }
        if(c>=d) return false;
        return true;
    }
    
    int shipWithinDays(vector<int>& w, int D) {
        int l=0;
        long long r=0;
        int n=w.size();
        for(int i=0;i<n;i++){
            r+=w[i];
            l=max(l,w[i]);
        }
        if(D<=1) return r;
        int ans=0;
        while(l<r){
            long long mid=(r-l)/2+l;
            if(!ship(w,D,mid)){
                l=mid+1;
            }else{
                ans=mid;
                r=mid;
            }
        }
        return ans;
    }
};