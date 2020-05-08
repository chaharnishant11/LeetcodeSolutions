#include <bits/stdc++.h>
using namespace std;

int helper(string s){
    map<pair<int,int>,int> m;
    int zc=0,oc=0,tc=0;
    m[{0,0}]=1;
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') zc++;
        else if(s[i]=='1') oc++;
        else tc++;
        pair<int,int> p={zc-oc,zc-tc};
        ans+=m[p];
        m[p]++;
    }
    return ans;
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    string s;
	    cin >> s;
	    cout << helper(s) << endl;
	}
	return 0;
}