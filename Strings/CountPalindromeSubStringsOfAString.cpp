#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    string s;
	    cin >> s;
	    bool P[n][n];
	    int dp[n][n];
	    memset(dp,0,sizeof(dp));
	    memset(P,false,sizeof(P));
	    for(int i=0;i<n;i++){
	        P[i][i]=true;
	    }
	    for (int i=0; i<n-1; i++){ 
            if (s[i] == s[i+1]){ 
                P[i][i+1] = true; 
                dp[i][i+1] = 1 ; 
            } 
        } 
	    for (int gap=2 ; gap<=n; gap++){ 
            for (int i=0; i<n-gap+1; i++){ 
                int j = gap + i -1; 
                if (s[i] == s[j] && P[i+1][j-1] ) 
                    P[i][j] = true; 
                if (P[i][j] == true) 
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1 - dp[i+1][j-1]; 
                else
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]; 
            } 
        }
	    cout << dp[0][n-1] <<  endl;
	}
	return 0;
}