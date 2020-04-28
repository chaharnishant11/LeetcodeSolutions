class Solution {
public:
    int nextGreaterElement(int num) {
        string s=to_string(num);
        int n=s.size(),i;
        for(i=n-1;i>0;i--){
            if(s[i]>s[i-1]) break;
        }
        if(i==0) return -1;
        int x=s[i-1],min=i;
        for(int j=i+1;j<n;j++){
            if(s[j]>x && s[j]<s[min]) min=j;
        }
        swap(s[i-1],s[min]);
        sort(s.begin()+i,s.end());
        long res = stol(s);
        return res > INT_MAX? -1 : res;
    }
};