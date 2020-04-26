class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) 
           return 1;
        if(n<0){
           unsigned int N=n;
           N=-N;
           x = 1/x;
           return (n%2==0) ? myPow(x*x, N/2) : x*myPow(x*x, N/2);
        }
        return (n%2==0) ? myPow(x*x, n/2) : x*myPow(x*x, n/2);
   
    }
};