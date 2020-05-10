class Solution {
public:
    int smallestDivisor(vector<int>& nums, int t) {
        int l=1;
        int r=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            r=max(r,nums[i]);
        }
        int ans=l;
        while(l<=r){
            int mid=(r-l)/2+l;
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=ceil(double(nums[i])/mid);
            }
            if(sum>t){
                l=mid+1;
            }else{
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
};