class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int x=target-nums[i];
            if(m.find(x)!=m.end()){
                ans.push_back(m[x]);
                ans.push_back(i);
                return ans;
            }
            if(m.find(nums[i])==m.end()){
                m[nums[i]]=i;
            }
        }
        return ans;


    }
};
