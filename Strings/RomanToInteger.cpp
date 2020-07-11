int Solution::romanToInt(string s) {
    int n=s.size();
    int a[n];
    for(int i=0;i<n;i++){
        if(s[i]=='I') a[i]=1;
        if(s[i]=='V') a[i]=5;
        if(s[i]=='X') a[i]=10;
        if(s[i]=='L') a[i]=50;
        if(s[i]=='C') a[i]=100;
        if(s[i]=='D') a[i]=500;
        if(s[i]=='M') a[i]=1000;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        if(i==n-1){
            sum+=a[i];
            break;
        }
        if(a[i]>=a[i+1])
            sum+=a[i];
        else
            sum-=a[i];
    }
    return sum;
}
