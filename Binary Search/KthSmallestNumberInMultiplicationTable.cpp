class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l=1,h=n*m;
        while(l<h){
            int mid=(h-l)/2+l;
            int ans=0;
            int x=mid;
            //cout << l << " " << mid << " " << h << endl;
            for(int i=1;i<=m;i++){
                //cout << x << " " << i << endl;
                ans+=min(x/i,n);
                //cout << ans << endl;
            }
            if(ans<k) l=mid+1;
            else h=mid;
        }
        return l;
    }
};