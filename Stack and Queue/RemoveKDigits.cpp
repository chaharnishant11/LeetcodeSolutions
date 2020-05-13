class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";                            
        stack<char> s;
        for( auto c : num){
            while(!s.empty() && s.top()>c && k){
                s.pop();
                k--;
            }
            if(!s.empty() || c!='0'){
                s.push(c);
            }
        }
        while(!s.empty() && k){
            s.pop();
            k--;
        }
        while(!s.empty()){
            ans=s.top()+ans;
            s.pop();
        }
        return (ans.size()==0)?"0":ans;
    }
};