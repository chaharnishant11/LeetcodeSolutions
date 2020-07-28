#define m 1000000007
int Solution::solve(int A, int B) 
{
    vector<vector<int>> v(A+1, vector<int>(B+1));
    
    for(int i=0; i<=min(9,B); i++)
        v[1][i]=1;
        
    for(int n=2; n<=A; n++){
        for(int s=0; s<=B; s++){
            for(int d=0; d<=min(s,9); d++){
                if(n==A && s==B && d==0)
                    continue;
                v[n][s] = (v[n][s] + v[n-1][s-d])%m;
            }
        }
    }
    return v[A][B];
}