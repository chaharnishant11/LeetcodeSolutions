class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()<1) return 0;
        if(target <= nums[0]) return 0;
        if(target > nums[nums.size()-1]) return nums.size();
        if(target == nums[nums.size()-1]) return nums.size()-1;
        int l=0;
        int h=nums.size()-1;
        int mid;
        int ans;
        while(l<=h){
            mid=(h+l)/2;
            if(nums[mid]==target) return mid;
            if(target<nums[mid]){
                ans=mid;
                h=mid-1;
            } 
            else{
                ans=mid+1;
                l=mid+1;
            } 
        }
        return ans;
    }
};