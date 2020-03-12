class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1) return nums.size();
        int n=nums.size();
        int j=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]){
                nums[j]=nums[i];
                j++;
            }
        }
        nums[j++]=nums[n-1];
        return j;
    }
};