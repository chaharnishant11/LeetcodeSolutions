#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin >>  t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin >> a[i];
	    int lis[n];
	    for(int i=0;i<n;i++){
	        lis[i]=a[i];
	    }
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(a[i]>a[j]){
	                lis[i]=max(lis[i],lis[j]+a[i]);
	            }
	        }
	    }
	    int ans=0;
	    for(int i=0;i<n;i++){
	        ans=max(ans,lis[i]);
	    }
	    cout << ans << endl;
	}
	return 0;
}