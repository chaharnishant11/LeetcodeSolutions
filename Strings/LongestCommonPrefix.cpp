string Solution::longestCommonPrefix(vector<string> &A) {
    int n=INT_MAX;
    for(int i=0;i<A.size();i++){
        if(n>A[i].length()){
            n=A[i].length();
        }
    }
    int xori=0;string str;
    for(int i=0;i<n;i++){
        for(int j=0;j<A.size();j++){
            xori=A[0][i]^A[j][i];
            if(xori!=0){
                return str;
            }
        }
        if(xori==0){
            str.push_back(A[0][i]);
        }
    }
    return str;
}
