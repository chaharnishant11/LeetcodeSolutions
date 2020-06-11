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
	    if(s.size()%2!=0){
	        cout << -1 << endl;
	    }else{
	        stack<char> st;
	        for(int i=0;i<s.size();i++){
	            if(!st.empty() && st.top()=='{' && s[i]=='}'){
	                st.pop();
	            }else{
	                st.push(s[i]);
	            }
	        }
	        int sizeofst=st.size();
	        int x=0;
	        while(!st.empty()){
	            if(st.top()=='{') x++;
	            st.pop();
	        }
	        int res=sizeofst/2+x%2;
	        cout << res << endl;
	    }
	}
	return 0;
}