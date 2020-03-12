class Solution {
public:
    void helper(vector<int> c,int t,vector<vector<int>>& res,vector<int> temp,int s){
        if(t==0){
            res.push_back(temp);
            return;
        }
        for(int i=s;i<c.size() && t>=c[i]; i++){
            if(i==s || c[i-1]!=c[i]){
                temp.push_back(c[i]);
                helper(c,t-c[i],res,temp,i+1);
                temp.pop_back();
            }
        }
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(),c.end());
        vector<vector<int>> res;
        vector<int> temp;
        helper(c,t,res,temp,0);
        return res;
    }
};