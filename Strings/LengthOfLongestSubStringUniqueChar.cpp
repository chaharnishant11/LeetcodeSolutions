#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    string s;
	    cin >> s;
	    int i=0,j=0;
	    int ans=0;
	    int n=s.size();
	    set<char> c;
	    while(j<n){
	        if(c.find(s[j])==c.end()){
	            c.insert(s[j]);
	            j++;
	            ans=max(ans,j-i);
	        }else{
	            c.erase(s[i]);
	            i++;
	        }
	    }
	    cout << ans << endl;
	}
	return 0;
}