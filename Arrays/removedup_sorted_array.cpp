class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0|| nums.size()==1)
            return nums.size();
            
        int start = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[start]!=nums[i]){
                start++;
                nums[start]= nums[i];
            }
        }
        return start+1;
    }
};
