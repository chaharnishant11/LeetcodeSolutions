class Solution {
public:
    unordered_map<string,vector<int>> dp;
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        if(dp.find(input)!=dp.end()) return dp[input];
        int n=input.size();
        for(int i=0;i<input.size();i++){
            if(input[i]=='*' || input[i]=='-' || input[i]=='+'){
                vector<int> pat1=diffWaysToCompute(input.substr(0,i));
                vector<int> pat2=diffWaysToCompute(input.substr(i+1,n-i-1));
                for(auto n1:pat1){
                    for(auto n2:pat2){
                        int c=0;
                        if(input[i]=='*'){
                            c=n1*n2;
                        }else if(input[i]=='+'){
                            c=n1+n2;
                        }else{
                            c=n1-n2;
                        }
                        ans.push_back(c);
                    }
                }
            }
        }
        if(ans.size()==0){
            ans.push_back(stoi(input));
        }
        dp[input]=ans;
        return ans;
    }
};