#include <bits/stdc++.h>
using namespace std;

void helper(int *a,int n,int k){
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=0;i<k;i++) q.push(a[i]);
    for(int i=0;i<n-k;i++){
        cout << q.top() << " ";
        q.pop();
        q.push(a[i+k]);
    }
    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n,k;
	    cin >> n >> k;
	    int a[n];
	    for(int i=0;i<n;i++) cin >> a[i];
	    helper(a,n,k);
	    cout << endl;
	}
	return 0;
}