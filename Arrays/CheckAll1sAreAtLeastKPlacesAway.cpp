// static auto fast=[]{ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
// class Solution {
// public:
//     bool kLengthApart(vector<int>& nums, int k) {
//         int s=0;
//         int c=0;
//         while(s<nums.size()){
//             if(nums[s]==1 && s!=0){
//                 if(c<k) return false;
//                 c=0;
//             }if(nums[s]==0) c++;
//             s++;
//         }
//         return true;
//     }
// };
// In this particular code currently in Leetcode it's passing 67/68 testcases and as a whole it's giving wrong answer after submission.
// So, I have added a different approach!

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        if (!k) return true;
        // parsing nums
        for (int i = 0, j = 0, len = nums.size(); i < len; i++) {
            // element == 1 && not enough distance from the previous
            if (nums[i] && j > 0) return false;
            // otherwise we either reset or decrease j
            else j = nums[i] ? k : j - 1;
        }
        return true;
    }
};
