#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    int dp[n+1]={0};
	    for(int i=0;i<n;i++){
	        dp[a[i]]=dp[a[i]-1]+1;
	    }
	    int maxx=0;
	    for(int i=1;i<=n;i++)
	        if(dp[i]>maxx)
	            maxx=dp[i];
	    cout<<n-maxx<<endl;
	}
	return 0;
}