#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n,m;
	    cin >> n >> m;
	    int g[n][m];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cin >> g[i][j];
	        }
	    }
	    int temp[n][m];
	    int ans=1;
	    for(int i=0;i<n;i++) temp[i][0]=g[i][0];
	    for(int i=0;i<m;i++) temp[0][i]=g[0][i];
	    for(int i=1;i<n;i++){
	        for(int j=1;j<m;j++){
	            if(g[i][j]==1){
	                temp[i][j]=min(min(temp[i-1][j],temp[i][j-1]),temp[i-1][j-1])+1;
	                ans=max(ans,temp[i][j]);
	            }else{
	                temp[i][j]=0;
	            }
	        }
	    }
	    cout << ans << endl;
	}
	
	return 0;
}