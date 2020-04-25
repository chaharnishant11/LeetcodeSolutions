class Solution {
public:
    int start(vector<int> nums,int t,int l,int r){
        if(l>r) return -1;
        int mid=l+(r-l)/2;
        if(nums[mid]==t){
            if(mid-1>=0 && nums[mid-1]==nums[mid]){
                return start(nums,t,l,mid-1);
            }else{
                return mid;
            }
        }
        if(nums[mid]>t){
            return start(nums,t,l,mid-1);
        } return start(nums,t,mid+1,r);
    }
    int end(vector<int> nums,int t,int l,int r){
        if(l>r) return -1;
        int mid=l+(r-l)/2;
        if(nums[mid]==t){
            if(mid+1<nums.size() && nums[mid+1]==nums[mid]){
                return end(nums,t,mid+1,r);
            }else{
                return mid;
            }
        }
        if(nums[mid]>t){
            return end(nums,t,l,mid-1);
        } return end(nums,t,mid+1,r);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int s=start(nums,target,0,nums.size()-1);
        int e=end(nums,target,0,nums.size()-1);
        return {s,e};
    }
};