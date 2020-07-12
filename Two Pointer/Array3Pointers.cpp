int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int n1 = A.size();
    int n2 = B.size();
    int n3 = C.size();
    int i=0, j=0, k=0;
    int ans = INT_MAX;
    while(i<n1 && j<n2 && k<n3){
        int t = max(max(abs(A[i]-B[j]),abs(A[i]-C[k])),abs(B[j]-C[k]));
        if(t<ans)
            ans = t;
        if(A[i]>=B[j] && B[j]<=C[k])
            j++;
        else if(A[i]<=B[j] && A[i]<=C[k])
            i++;
        else
            k++;
    }
    return ans;
    
}
