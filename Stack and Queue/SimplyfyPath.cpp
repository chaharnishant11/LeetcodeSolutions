string Solution::simplifyPath(string A) {
    stack<string> st;
    for(int i = 0;i<A.length();i++){
        if(A[i] == '/')
        continue;
        else{
            string s = "";
            while(A[i] != '/' && i < A.length()){
                s += (A[i]);
                i++;
            }
            if(s == ".."){
                if(!st.empty())
                st.pop();
            }
            else if(s == ".")
                continue;
            else
                st.push(s);
        }
    }
    if(st.empty()){
        return "/";
    }
    string ans = "";
    while(!st.empty()){
        string temp = st.top();
        reverse(temp.begin(),temp.end());
        ans += temp;
        ans += '/';
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
