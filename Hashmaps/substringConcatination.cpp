vector<int> Solution::findSubstring(string s, const vector<string> &a) {
    vector<int> res;
    int n=s.size();
    int l=(a.size())*(a[0].size());
    int w=a[0].size();
    unordered_map<string,int> m,temp;
    for(auto it:a)
        m[it]++;
    for(int i=0;i<n-l+1;i++){
        for(int j=i;j<i+l;j+=w){
            string x=s.substr(j,w);
            temp[x]++;
        }
        if(m==temp){
            res.push_back(i);
        }
        temp.clear();
    }
    return res;
    
}
