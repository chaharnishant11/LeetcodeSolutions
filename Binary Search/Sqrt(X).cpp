class Solution {
public:
    int mySqrt(int x) {
        int left=0;
        int right=x;
        int ans=x;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(mid*mid==x)return mid;
            else if(mid*mid>x){
                right=mid-1;
            }else{
                left=mid+1;
                ans=mid;
            }
        }
        return ans;
    }
};