class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        deque<int> mi;
        deque<int> ma;
        int i=0,j;
        for(j=0;j<n;j++){
            while(!mi.empty() && nums[j]<mi.back()) mi.pop_back();
            while(!ma.empty() && nums[j]>ma.back()) ma.pop_back();
            ma.push_back(nums[j]);
            mi.push_back(nums[j]);
            if(ma.front()-mi.front()>limit){
                if(mi.front()==nums[i]) mi.pop_front();
                if(ma.front()==nums[i]) ma.pop_front();
                i++;
            }
        }
        return j-i;
    }
};