#include <bits/stdc++.h>
using namespace std;

bool helper(int *a,int n,int k){
    if(n%2!=0) return false;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        m[a[i]%k]++;
    }
    for(int i=0;i<n;i++){
        int rem=a[i]%k;
        if(2*rem==k){
            if(m[rem]%2!=0) return false; // if rem = k/2 then there should be 2*m[rem] 
        }
        if(rem==0){
            if(m[rem]&1) return false; // if rem is 0 then there should be even number of m[rem]
        } 
        else if(m[rem]!=m[k-rem]) return false;
    }
    return true;
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
	    if(helper(a,n,k)) cout << "True" << endl;
	    else cout << "False" << endl;
	}
	return 0;
}


// With Negative Numbers 

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        if (n & 1) 
        return false; 
        unordered_map<int, int> freq; 
        for (int i = 0; i < n; i++){
            if(arr[i]<0){
                freq[abs(arr[i]) % k]--; 
            }else freq[arr[i] % k]++; 
        }
            
        //for(auto i:freq) cout << i.first << " " << i.second << endl;
        for (int i = 0; i < n; i++){ 
            int rem = arr[i] % k; 
            if  (2*rem == k){ 
                if (freq[rem] % 2 != 0) 
                    return false; 
            }
            else if (rem == 0){ 
               if (freq[rem] & 1)            
                   return false; 
            } 
            else if (freq[rem] != freq[k - rem]) 
                return false; 
        } 
        return true; 
    }
};