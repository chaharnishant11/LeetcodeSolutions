// C++ implementation to print the bracket number 
#include <bits/stdc++.h> 

using namespace std; 

// function to print the bracket number 
void printBracketNumber(string exp, int n) 
{ 
	// used to print the bracket number 
	// for the left bracket 
	int left_bnum = 1; 
	
	// used to obtain the bracket number 
	// for the right bracket 
	stack<int> right_bnum; 
	
	// traverse the given expression 'exp' 
	for (int i = 0; i < n; i++) { 
		
		// if current character is a left bracket 
		if (exp[i] == '(') { 
			// print 'left_bnum', 
			cout << left_bnum << " "; 
			
			// push 'left_bum' on to the stack 'right_bnum' 
			right_bnum.push(left_bnum); 
			
			// increment 'left_bnum' by 1 
			left_bnum++; 
		} 
		
		// else if current character is a right bracket 
		else if(exp[i] == ')') { 

			// print the top element of stack 'right_bnum' 
			// it will be the right bracket number 
			cout << right_bnum.top() << " "; 
			
			// pop the top element from the stack 
			right_bnum.pop(); 
		} 
	} 
} 

// Driver program to test above 
int main() 
{ 
	string exp = "(a+(b*c))+(d/e)"; 
	int n = exp.size(); 
	
	printBracketNumber(exp, n); 
	
	return 0; 
} 
