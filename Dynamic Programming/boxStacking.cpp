// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int maxHeight(int height[],int width[],int length[],int n);

int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	

 	int A[1000],B[1000],C[10001];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	cout<<maxHeight(A,B,C,n)<<endl;
}
 
} // } Driver Code Ends
/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/
struct dim{
    int h,l,w;
};

int compare(const dim a,const dim b){
    return (a.l*a.w)>(b.l*b.w);
}

int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    dim boxes[3*n];
    int j=0;
    for(int i=0;i<n;i++){
        boxes[j].h=height[i];
        boxes[j].l=max(width[i],length[i]);
        boxes[j].w=min(width[i],length[i]);
        j++;
        boxes[j].h=length[i];
        boxes[j].l=max(width[i],height[i]);
        boxes[j].w=min(width[i],height[i]);
        j++;
        boxes[j].h=width[i];
        boxes[j].l=max(height[i],length[i]);
        boxes[j].w=min(height[i],length[i]);
        j++;
    }
    n=3*n;
    sort(boxes,boxes+n,compare);
    int m[n];
    for(int i=0;i<n;i++){
        m[i]=boxes[i].h;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(boxes[j].w>boxes[i].w && boxes[j].l>boxes[i].l){
                m[i]=max(m[i],m[j]+boxes[i].h);
            }
        }
    }
    int ans=-1;
    for(int i=0;i<n;i++){
        ans=max(ans,m[i]);
    }
    return ans;
    
}