class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l=1;
        int r=1000000000;
        while(l<r){
            int mid=(r-l)/2+l;
            int time=0;
            for (int p : piles) time += (p + mid - 1) / mid;
            if(time>H){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return l;
    }
};