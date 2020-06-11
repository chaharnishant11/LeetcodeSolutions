#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    string s;
	    cin >> s;
	    stack<int> st;
	    st.push(-1);
	    int res=0;
	    for(int i=0;i<s.size();i++){
	        if(s[i]=='('){
	            st.push(i);
	        }
	        else{
	            st.pop();
	            if(!st.empty()) res=max(res,i-st.top());
	            else st.push(i);
	        }
	    }
	    cout << res << endl;
	}
	return 0;
}