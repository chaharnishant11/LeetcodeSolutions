#include <bits/stdc++.h>
using namespace std;

int helper(int n,int* a){
    unordered_map<int,int> m;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=(a[i]==0)?-1:1;
        m[sum]++;
    }
    int ans=0;
    for(auto i=m.begin();i!=m.end();i++){
        if(i->second>1){
            ans+=(i->second*(i->second-1))/2;
        }
    }
    if(m.find(0)!=m.end()){
        ans+=m[0];
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
	    for(int i=0;i<n;i++){
	        cin >> a[i];
	    }
	    cout << helper(n,a) << endl;
	}
	return 0;
}