int Solution::solve(const vector<int> &A) {
    map<int,int> m;
    int n=A.size();
    if(n==0) return 0;
    for(int i=0;i<A.size();i++){
        m[A[i]]++;
    }
    if(m.size()==1) return m[A[0]];
    map<int,vector<int>> ap;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(ap.find(abs(A[i]-A[j]))==ap.end()){
                ap[abs(A[i]-A[j])].push_back(min(A[i],A[j]));
            }else{
                int d=abs(A[i]-A[j]);
                int minn=min(A[i],A[j]);
                ap[d][0]=min(ap[d][0],minn);
            }
        }
    }
    for(auto i:ap){
        int d=i.first;
        int s=i.second[0];
        while(true){
            if(m.find(s+d)!=m.end()){
                ap[d].push_back(s+d);
                s=s+d;
            }else{
                break;
            }
        }
    }
    int ans=0;
    for(auto i:ap){
        int s=i.second.size();
        ans=max(s,ans);
    }
    return ans;
}
