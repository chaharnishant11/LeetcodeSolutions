#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int a[n][n];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            cin >> a[i][j];
	        }
	    }
	    int degree[n];
	    for(int i=0;i<n;i++) degree[i]=0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(a[i][j]==1){
	                degree[i]++;
	            }
	        }
	    }
	    int odd=0;
	    int even=0;
	    for(int i=0;i<n;i++){
	        if(degree[i]%2==0){
	            even++;
	        }else odd++;
	    }
	    if(odd==2) cout << 1 << endl;
	    else cout << 0 << endl;
	}
	return 0;
}