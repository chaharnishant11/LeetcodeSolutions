static auto fast=[]{ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int s=0;
        int c=0;
        while(s<nums.size()){
            if(nums[s]==1 && s!=0){
                if(c<k) return false;
                c=0;
            }if(nums[s]==0) c++;
            s++;
        }
        return true;
    }
};