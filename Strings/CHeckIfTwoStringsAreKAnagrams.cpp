// { Driver Code Starts
#include<iostream>
using namespace std;
const int MAX_CHAR = 26;
bool areKAnagrams(string str1, string str2, int k);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		if (areKAnagrams(str1, str2, k) == true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}// } Driver Code Ends

#include<bits/stdc++.h>
using namespace std;
/*Complete the function below*/
bool areKAnagrams(string str1, string str2, int k)
{
    //add code here.
    if(str1.size()!=str2.size()) return false;
    int s1[27]={0};
    int s2[27]={0};
    int c=0;
    //cout << str1 << endl;
    //cout << str2 << endl;
    for(int i=0;i<str1.size();i++){
        s1[str1[i]-'a']++;
        s2[str2[i]-'a']++;
    }
    for(int i=0;i<27;i++){
        c+=abs(s1[i]-s2[i]);
    }
    c=c/2;
    return c<=k;
}