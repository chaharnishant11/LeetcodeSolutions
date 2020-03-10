class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        while(i<nums.size() && i<=j){
            if(nums[i]<=0){
                swap(nums[i],nums[j]);
                j--;
            }else{
                i++;
            }
        }
        for(i=0;i<=j && i<nums.size();i++){
            if(nums[i]-1<=j && nums[nums[i]-1]!=nums[i]){
                swap(nums[nums[i]-1],nums[i]);
                if(nums[i]<=j && i+1!=nums[i]) i--;
            }
        }
        for(i=0;i<=j && i<nums.size();i++){
            if(nums[i]!=i+1) return i+1;
        }
        return j+2;
    }
};
