#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int g[n][n];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            cin >> g[i][j];
	        }
	    }
	    int deg[n];
	    int zero=0;
	    for(int i=0;i<n;i++) deg[i]=0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(g[i][j]==1){
	                deg[i]++;
	            }
	        }
	    }
	    int odd=0;
	    for(int i=0;i<n;i++){
	        if(deg[i]%2!=0) odd++;
	        if(deg[i]==0) zero++;
	    }
	    if((odd==0 && zero==0)|| n==1) cout << "True" << endl;
	    else cout << "False" << endl;
	}
	return 0;
}