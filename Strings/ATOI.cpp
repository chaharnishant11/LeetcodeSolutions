class Solution {
public:
    int myAtoi(string A) {
        long long ans=0;
        int i=0;
        while(i<A.size() && A[i]==' ') i++;
        while(i<A.size() && (A[i]<'0' && A[i]>'9') && (A[i]!='-' || A[i]!='+')) i++;
        if(i>=A.size()) return 0;
        bool neg=false;
        if(A[i]=='-'){
            neg=true;
            i++;
        } 
        else if(A[i]=='+') i++;
        for(;i<A.size();i++){
            if(A[i]<'0' || A[i]>'9') break;
            ans=ans*10+(A[i]-'0');
            if(ans>INT_MAX){
                if(neg) return INT_MIN;
                else return INT_MAX;
            }
        }
        if(neg) ans=-1*ans;
        return ans;
    }
};


