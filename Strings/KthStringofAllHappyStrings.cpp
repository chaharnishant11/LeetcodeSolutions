class Solution {
public:
    string helper(int n,int p,int& k,char last_ch=0){
        if(p==n) --k;
        else{
            for (char ch = 'a'; ch <= 'c'; ++ch) {
                if (ch != last_ch) {
                    auto res = helper(n, p+1, k, ch);
                    if (k == 0)
                        return string(1, ch) + res;
                }
            }
        }
        return "";
    }
    string getHappyString(int n, int k) {
        return helper(n,0,k,0);
    }
};