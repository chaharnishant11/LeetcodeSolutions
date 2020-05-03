class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> s;
        vector<int> ans(n,-1);
        for(int i=2*n-1;i>=0;i--){
            while(!s.empty() && nums[i%n]>=nums[s.top()]) s.pop();
            ans[i%n]=s.empty()?-1:nums[s.top()];
            s.push(i%n);
        }
        return ans;
    }
};