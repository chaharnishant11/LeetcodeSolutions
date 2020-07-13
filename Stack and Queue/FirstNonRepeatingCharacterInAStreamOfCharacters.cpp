string Solution::solve(string A) {
    vector<int> count(26,0);
    queue<char> q;
    string ans="";
    for(int i=0;i<A.size();i++){
        count[A[i]-'a']++;
        q.push(A[i]);
        if(count[q.front()-'a']==1) ans+=q.front();
        else{
            while(!q.empty() && count[q.front()-'a']>1) q.pop();
            ans+=(q.empty())?'#':q.front();
        }
    }
    return ans;
}
