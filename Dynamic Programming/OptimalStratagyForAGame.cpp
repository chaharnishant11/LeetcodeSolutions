#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

int helper(int* a,int n,int l,int r,int sum){
    if(r==l+1){
        return max(a[l],a[r]);
    }
    if(dp[l][r]!=-1) return dp[l][r];
    int ans=sum-helper(a,n,l+1,r,sum-a[l]);
    ans=max(ans,sum-helper(a,n,l,r-1,sum-a[r]));
    dp[l][r]=ans;
    return ans;
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int a[n];
	    memset(dp,-1,sizeof(dp));
	    int sum=0;
	    for(int i=0;i<n;i++){
	        cin >> a[i];
	        sum+=a[i];
	    }
	    int ans=helper(a,n,0,n-1,sum);
	    cout << ans << endl;
	}
	return 0;
}