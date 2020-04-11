class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int l[n];
        int r[n];
        if(n==2) return {nums[1],nums[0]};
        l[0]=nums[0];
        r[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            l[i]=l[i-1]*nums[i];
        }
        for(int i=n-2;i>=0;i--){
            r[i]=r[i+1]*nums[i];
        }
        vector<int> ans;
        ans.push_back(r[1]);
        for(int i=1;i<n-1;i++){
            ans.push_back(l[i-1]*r[i+1]);
        }
        ans.push_back(l[n-2]);
        return ans;
    }
};