class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int inc=nums[0];
        int exc=0;
        for(int i=1;i<n-1;i++){
            int temp=inc;
            inc=max(inc,exc+nums[i]);
            exc=temp;
        }
        int ans=max(inc,exc);
        inc=nums[1];
        exc=0;
        for(int i=2;i<n;i++){
            int temp=inc;
            inc=max(inc,exc+nums[i]);
            exc=temp;
        }
        inc=max(inc,exc);
        return max(ans,inc);
        
    }
};