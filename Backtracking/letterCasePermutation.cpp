class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> vs;
        helper(vs,S,0);
        return vs;
    }
    
    void helper(vector<string>& vs,string& S,int p){
        if(p == S.size()) {
            vs.push_back(S);
            return ;
        }
        if(isdigit(S[p])) helper(vs,S,p+1);
        else if(islower(S[p])){
            helper(vs,S,p+1);
            S[p] += 'A'-'a';
            helper(vs,S,p+1);
        }
        else if(isupper(S[p])){
            helper(vs,S,p+1);
            S[p] += 'a'-'A';
            helper(vs,S,p+1);
        }
    }
};