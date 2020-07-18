vector<string> generate(int n){
    string num=to_string(n);
    vector<string> ans;
    for(int i=1;i<=num.size();i++){
        for(int j=0;j<=num.size()-i;j++){
           ans.push_back(num.substr(j,i));
        }
    }
    return ans;
}

int Solution::colorful(int A) {
    vector<string> nums=generate(A);
    unordered_map<int,bool> m;
    for(int i=0;i<nums.size();i++){
        int mul=1;
        for(int j=0;j<nums[i].size();j++){
            mul*=(nums[i][j]-'0');
        }
        //cout << nums[i] << " " << mul << endl;
        if(m.find(mul)!=m.end()) return 0;
        m[mul]=true;
    }
    return 1;
}
