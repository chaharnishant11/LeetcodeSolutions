#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int a,b;
	    a=1;
	    b=1;
	    int m=1000000007;
	    for(int i=1;i<=n;i++){
	        int tmp = a;
        	a = (a%m + b%m)%m;
            b = tmp;
	    }
	    cout << a << endl;
	}
	return 0;
}