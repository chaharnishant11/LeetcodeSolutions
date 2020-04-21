class Solution {
public:
    bool isPalindrome(string str,int s,int e){
        while(s<=e){
            if(str[s++]!=str[e--]) return false;
        }
        return true;
    }
    
    void dfs(string s,vector<string>& temp,vector<vector<string>>& ans,int index){
        if(s.size()==index){
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                dfs(s,temp,ans,i+1);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>> ans;
        vector<string> temp;
        dfs(s,temp,ans,0);
        return ans;
    }
};