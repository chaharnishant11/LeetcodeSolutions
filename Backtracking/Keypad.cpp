class Solution {
public:
    vector<string> helper(string digits){
        vector<string> ans;
        if(digits.size()==0){
            ans.push_back("");
            return ans;
        }
        vector<string> c = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> temp=helper(digits.substr(1,digits.size()));
        int n=digits[0]-'0';
        for(int j=0;j<c[n].size();j++){
            for(int i=0;i<temp.size();i++){
                ans.push_back(c[n][j]+temp[i]);
            }
        }
        return ans;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans;
        return helper(digits);

    }
};
