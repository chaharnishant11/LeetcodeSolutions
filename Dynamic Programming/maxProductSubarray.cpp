//APPROACH 1

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        for(int i=1,imax=ans,imin=ans;i<nums.size();i++){
            if(nums[i]<0){
                swap(imax,imin);
            }
            imax=max(nums[i],nums[i]*imax);
            imin=min(nums[i],nums[i]*imin);
            ans=max(ans,imax);
        }
        return ans;
    }
};

//APPROACH 2

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),res=nums[0],l=0,r=0;
        for(int i=0;i<n;i++){
            l=((l!=0)?l:1)*nums[i];
            r=((r!=0)?r:1)*nums[n-1-i];
            res = max(res, max(l, r));
        }
        return res;
    }
};