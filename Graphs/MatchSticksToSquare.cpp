class Solution {
    bool dfs(vector<int> &sum,const vector<int> &nums, int id, const int t) {
        if(id==nums.size())
            return sum[0] == sum[1] && sum[1] == sum[2] && sum[2] == sum[3];
        
        for(int i = 0; i < 4; ++i) {
            if(sum[i]+nums[id]>t) continue;
            int j = i;
            while(--j >= 0)
                if(sum[i]==sum[j]) 
                    break;
            if (j!=-1) continue;
           sum[i]+=nums[id];
            if (dfs(sum,nums,id+1,t))
                return true;
            sum[i]-=nums[id];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int sum = 0;
        for(auto val:nums) sum += val;
        if (sum % 4 != 0) return false;
        sort(nums.begin(), nums.end(), [](const int &l, const int &r){return l > r;}); // second
        vector<int> sidesLength(4, 0);
        return dfs(sidesLength, nums, 0, sum / 4);
    }
};