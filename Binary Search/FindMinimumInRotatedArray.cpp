class Solution {
public:
    int helper(vector<int> nums,int l,int r){
        if(l==r) return nums[l];
        if(l>r) return -1;
        int mid=(l+r)/2;
        if(nums[mid]>nums[mid+1]) return nums[mid+1];
        if(nums[mid]>nums[r]){
            return helper(nums,mid+1,r);
        }
        return helper(nums,l,mid);
    }
    int findMin(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};