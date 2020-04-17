#include<bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0);cin.tie(0)
#define int long 
#define f first
#define s second 
#define pb push_back
#define mod 1000000007
#define pa pair<int,int>

bool sortgrt(const pa &a,const pa &b)
{
    return a.f * b.s>b.f*a.s;
}

int32_t main()
{
    boost;
    int t;
    cin >> t;
    while(t--)
    {
        int n,w,x,y;
        float cnt=0.0;
        cin >> n >> w;
        vector<pa> vect(n);
        for(int i=0;i<n;i++)
        {
            cin >> x >> y;
            vect[i]={x,y};
        }
        sort(vect.begin(),vect.end(),sortgrt);
        for(int i=0;i<n&&w;i++)
        {
            if(w>=vect[i].s)
            {
                cnt+= (1.0)*(vect[i].f);
                w-=vect[i].s;
            }
            else 
            {
                cnt+= (((1.0)*(w))/vect[i].s) * vect[i].f;
                w=0;
            }
        }

        cout << fixed << setprecision(2) << cnt << endl;
        
    }
}