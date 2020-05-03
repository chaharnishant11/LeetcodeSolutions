#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int a[n];
	    for(int i=0;i<n;i++) cin >> a[i];
	    stack<int> s;
	    int ans[n];
	    for(int i=0;i<n;i++){
	        while(!s.empty() && a[i]>=a[s.top()]) s.pop();
	        ans[i]=s.empty()?i+1:i-s.top();
	        s.push(i);
	    }
	    for(int i=0;i<n;i++) cout << ans[i] << " ";
	    cout << endl;
	    
	}
	return 0;
}