class Solution {
public:
    string fractionToDecimal(int num, int den) {
        if(!num) return "0";
        string ans="";
        if(num>0^den>0){
            ans+='-';
        }
        long long n=llabs(num),d=llabs(den);
        long long r=n%d;
        ans += to_string(n / d);
        if(r==0){
            return ans;
        } 
        unordered_map<long long,int> m;
        ans+='.';
        while(r){
            if(m.find(r)!=m.end()){
                ans.insert(m[r], "(");
                ans += ')';
                break;
            }else{
                m[r]=ans.size();
                r *= 10;
                ans += to_string(r / d);
                r %= d;
            }
        }
        return ans;
    }
};