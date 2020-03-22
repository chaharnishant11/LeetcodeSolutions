// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 



int findMaxDiff(int [], int n);

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	int n;
   	cin>>n;
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	cout<<findMaxDiff(a,n)<<endl;
   }
    return 0;
}


// } Driver Code Ends
/*You are required to complete this method */
int findMaxDiff(int A[], int n)
{
  //Your code here
  int l[n];
  int r[n];
  stack<int> s;
  for(int i=n-1;i>=0;i--){
      while(!s.empty() && A[i]<=s.top()) s.pop();
      l[i]=s.empty()?0:s.top();
      s.push(A[i]);
  }
  while(!s.empty()) s.pop();
  for(int i=0;i<n;i++){
      while(!s.empty() && A[i]<=s.top()) s.pop();
      r[i]=s.empty()?0:s.top();
      s.push(A[i]);
  }
  int ans=INT_MIN;
  for(int i=0;i<n;i++){
      ans=max(ans,abs(l[i]-r[i]));
  }
  return ans;
}