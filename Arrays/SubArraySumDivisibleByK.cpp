#include <bits/stdc++.h> 
using namespace std; 
int subCount(int arr[], int n, int k){
	int mod[k]; 
	memset(mod, 0, sizeof(mod)); 
	int cumSum = 0; 
	for (int i = 0; i < n; i++) { 
		cumSum += arr[i]; 

		// as the sum can be negative, taking modulo twice 
		mod[((cumSum % k) + k) % k]++; 
	} 
	int result = 0;  
	for (int i = 0; i < k; i++) 
		if (mod[i] > 1) 
			result += (mod[i] * (mod[i] - 1)) / 2; 
	result += mod[0]; 

	return result; 
} 

// Driver program to run the case 
int main() 
{ 
	int t;
	cin >> t;
	while(t--){
	    int n,k;
	    cin >>n >> k;
	    int a[n];
	    for(int i=0;i<n;i++) cin >> a[i];
	    cout << subCount(a, n, k) << endl; 
	}
	return 0; 
} 