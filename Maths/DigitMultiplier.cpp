#include <bits/stdc++.h>
using namespace std;

void helper(int n){
    if(n<10){
        cout << n << endl; 
        return;
    } 
    vector<int> num;
    for(int i=9;i>1;i--){
        while(n%i==0){
            n/=i;
            num.push_back(i);
        }
    }
    if(n>10){
        cout << -1 << endl;
        return;
    }
    for(int i=num.size()-1;i>=0;i--){
        cout << num[i];
    }
    cout << endl;
    return;
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    helper(n);
	}
	return 0;
}