class Solution {
public:
    string decodeString(string s) {
        string ans="";
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]!=']'){
                st.push(s[i]);
            }else{
                string curr="";
                while(st.top()!='['){
                    curr=st.top()+curr;
                    st.pop();
                }
                string num="";
                st.pop();
                while(!st.empty() && isdigit(st.top())){
                    num=st.top()+num;
                    st.pop();
                }
                int k=stoi(num);
                for(int j=0;j<k;j++){
                    for(int n=0;n<curr.size();n++){
                        st.push(curr[n]);
                    }
                }
            }
        }
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};