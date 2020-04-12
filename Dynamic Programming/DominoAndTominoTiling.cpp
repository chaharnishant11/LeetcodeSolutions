class Solution {
public:
    int numTilings(int N) {
        int f[N+1];
        int p[N+1];
        if(N==0) return 0;
        if(N==1) return 1;
        if(N==2) return 2;
        f[0]=0;
        f[1]=1;
        f[2]=2;
        p[0]=0;
        p[1]=0;
        p[2]=2;
        int m=1000000007;
        for(int i=3;i<=N;i++){
            f[i]=(f[i-1]%m+(f[i-2]%m+p[i-1]%m)%m)%m;
            p[i]=(p[i-1]%m+2*f[i-2]%m)%m;
        }
        return f[N]%m;
    }
};