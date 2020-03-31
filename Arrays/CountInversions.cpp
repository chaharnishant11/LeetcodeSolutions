#include <bits/stdc++.h>
using namespace std;
long merge(int a[],int temp[],int s,int mid,int e){ 
    int i, j, k; 
    long ans = 0; 
    i = s;
    j = mid; 
    k = s;
    while ((i <= mid - 1) && (j <= e)) { 
        if (a[i] <= a[j]) { 
            temp[k++] = a[i++]; 
        } 
        else { 
            temp[k++] = a[j++]; 
            ans = ans + (mid - i); 
        } 
    } 
    while (i <= mid - 1) 
        temp[k++] = a[i++]; 
    while (j <= e) 
        temp[k++] = a[j++]; 
    for (i = s; i <= e; i++) 
        a[i] = temp[i]; 
  
    return ans; 
}  
long helper(int a[], int temp[], int s, int e){ 
    int mid;
    long ans = 0; 
    if (e > s) { 
        mid = (e + s) / 2; 
        ans+=helper(a, temp, s, mid); 
        ans+=helper(a, temp, mid + 1, e); 
        ans+=merge(a, temp, s, mid + 1, e); 
    } 
    return ans; 
} 
long mergeSort(int a[], int n){ 
    int temp[n]; 
    return helper(a, temp, 0, n - 1); 
} 

int main() {
	//code
	int t=0;
	cin >> t;
	while(t--){
	    int n;
	    cin >>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin >> a[i];
	    long ans=mergeSort(a,n);
	    cout << ans << endl;
	}
	return 0;
}