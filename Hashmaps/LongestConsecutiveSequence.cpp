class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> m;
        for(int i=0;i<nums.size();i++){
            m.insert(nums[i]);
        }
        int ans=0;
        int n=nums.size();
        for( auto i : m){
            if(m.find(i-1)==m.end()){
                int cn=i;
                int temp=1;
                while(m.find(cn+1)!=m.end()){
                    cn++;
                    temp++;
                }
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};