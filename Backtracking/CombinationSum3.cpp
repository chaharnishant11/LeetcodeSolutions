class Solution {
public:
    set<vector<int>> s;
    void helper(vector<vector<int>>& ans,vector<int>& temp,int k,int n,int num,int sum){
        if(sum>n) return;
        if(sum==n && temp.size()==k){
            if(s.insert(temp).second) ans.push_back(temp);
            return;
        }
        if(temp.size()>=k) return;
        for(int i=num;i<=9;i++){
            temp.push_back(i);
            helper(ans,temp,k,n,i+1,sum+i);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans,temp,k,n,1,0);
        return ans;
    }
};