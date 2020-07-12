vector<int> Solution::maxone(vector<int> &A, int B) {
    int n=A.size();
    int i=0,j=0,c=0;
    int len=0;
    int s=0;
    int maxlen=0;
    while(j<n){
        if(A[j]==0) c++;
        while(c>B){
            if(A[i++]==0) c--;
        }
        len=j-i+1;
        if(len>maxlen){
            maxlen=len;
            s=i;
        }
        j++;
    }
    vector<int> ans;
    for(i=s;i<s+maxlen;i++) ans.push_back(i);
    return ans;
}
