class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l[n];
        l[0]=nums[0];
        for(int i=1;i<n;i++){
            l[i]=l[i-1]+nums[i];
        }
        int r[n];
        r[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            r[i]=r[i+1]+nums[i];
        }
        int index=0;
        for(int i=n-1;i>0;i--){
            if(r[i]>l[i-1]){
                index=i;
                break;
            }
        }
        vector<int> ans;
        for(int i=n-1;i>=index;i--){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};