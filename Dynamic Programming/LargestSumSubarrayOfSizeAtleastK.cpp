#include <iostream>
using namespace std;

int helper(int* a,int n,int k){
    int maxSum[n];
    maxSum[0]=a[0];
    int currsum=a[0];
    for(int i=1;i<n;i++){
        currsum=max(a[i],currsum+a[i]);
        maxSum[i]=currsum;
        cout << maxSum[i] << " ";
    }
    cout << endl;
    int sum=0;
    for(int i=0;i<k;i++) sum+=a[i];
    int ans=sum;
    for(int i=k;i<n;i++){
        sum=sum+a[i]-a[i-k];
        ans=max(ans,max(sum,maxSum[i-k]+sum));
    }
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
	    for(int i=0;i<n;i++) cin >> a[i];
	    int k;
	    cin >> k;
	    cout << helper(a,n,k) << endl;
	}
	return 0;
}