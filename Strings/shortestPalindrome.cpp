class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string rev(s);
        reverse(rev.begin(), rev.end());
        string s_new = s + "#" + rev;
        int n_new = s_new.size();
        vector<int> f(n_new, 0);
        int i=1,len=0;
        while(i<n_new){
            if(s_new[i]==s_new[len]){
                len++;
                f[i]=len;
                i++;
            }else{
                if(len>0){
                    len=f[len-1];
                }else{
                    i++;
                }
            }
        }
        return rev.substr(0, n - f[n_new - 1]) + s;
    }
};