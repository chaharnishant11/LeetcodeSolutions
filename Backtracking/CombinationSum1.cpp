/* Without duplicate elements with repetition allowed*/


class Solution {
public:
    void helper(vector<int> c,int t,vector<vector<int>>& ans,vector<int> temp,int s){
        if(t==0){
            ans.push_back(temp);
            return;
        }
        for(int i=s;i<c.size() && t-c[i]>=0;i++){
            temp.push_back(c[i]);
            helper(c,t-c[i],ans,temp,i);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        sort(c.begin(),c.end());
        vector<vector<int>> res;
        vector<int> temp;
        helper(c,t,res,temp,0);
        return res;
    }
};