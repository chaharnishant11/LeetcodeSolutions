class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3)return -1;
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2];
        int n=nums.size();
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int x=nums[i]+nums[j]+nums[k];
                if(x==target) return x;
                if(x>target){
                    if(abs(x-target)<abs(ans-target)){
                        ans=x;
                    }
                    k--;
                }if(x<target){
                    if(abs(x-target)<abs(ans-target)){
                        ans=x;
                    }
                    j++;
                }
            }
        }
        return ans;
    }
};
