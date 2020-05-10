class Solution {
public:
    bool poss(vector<int> nums,int m,long long limit){
        long long sum=0;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=limit)sum+=nums[i];
            else{
                c++;
                if(nums[i]>limit)return false;
                sum=nums[i];
            }
        }
        if(c>=m) return false;
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int l=0;
        long long r=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            l=max(l,nums[i]);
            r+=nums[i];
        }
        int ans=r;
        if(m<=1) return r;
        if(m>=n) return l;
        while(l<r){
            long long mid=(r-l)/2+l;
            if(!poss(nums,m,mid)){
                l=mid+1;
            }else{
                ans=mid;
                r=mid;
            }
        }
        return ans;
    }
};