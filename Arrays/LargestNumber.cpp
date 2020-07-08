static bool compare(int a,int b){
    string A=to_string(a);
    string B=to_string(b);
    int i=0,j=0;
    long long num1=stoll(A+B);
    long long num2=stoll(B+A);
    return num1>num2;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<int> temp(A.begin(),A.end());
    sort(temp.begin(),temp.end(),compare);
    string ans="";
    for(int i=0;i<A.size();i++){
        ans+=to_string(temp[i]);
    }
    int i=0;
    while(ans[i]=='0') i++;
    int n=ans.size();
    ans=ans.substr(i,n-i);
    return ans.size()==0?"0":ans;
}
