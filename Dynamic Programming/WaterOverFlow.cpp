#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    float X;
	    int i,j;
	    cin >> X >> i >> j;
	    float glass[i * (i + 1) / 2]; 
        memset(glass, 0, sizeof(glass));
        int index = 0; 
        glass[index] = X;
        for (int row = 1; row <= i ; ++row){
            for (int col = 1; col <= row; ++col, ++index){ 
                X = glass[index]; 
                glass[index] = (X >= 1.0f) ? 1.0f : X; 
                X = (X >= 1.0f) ? (X - 1) : 0.0f;  
                glass[index + row] += X / 2; 
                glass[index + row + 1] += X / 2; 
            } 
        } 
        cout <<  glass[i*(i-1)/2 + j - 1] <<  endl; 
	}
	return 0;
}