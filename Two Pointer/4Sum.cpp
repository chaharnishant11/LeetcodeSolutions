class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        map<vector<int>,bool> map;
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int k=j+1;
                int l=n-1;
                while(k<l){
                    int x=nums[i]+nums[j]+nums[k]+nums[l];
                    if(x==target){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[l]);
                        if(map.find(temp)==map.end()){
                            ans.push_back(temp);
                            map[temp]=true;
                        }
                        k++;
                        l--;
                    }if(x>target){
                        l--;
                    }if(x<target){
                        k++;
                    }
                }
            }
        }
        return ans;
    }
};
