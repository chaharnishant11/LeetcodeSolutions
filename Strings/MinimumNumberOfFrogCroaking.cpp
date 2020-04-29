class Solution {
public:
    int minNumberOfFrogs(string cf) {
        int cnt[5]={0};
        int frog=0;
        int maxFrog=0;
        for( auto i : cf){
            auto x=string("croak").find(i);
            ++cnt[x];
            if(x==0){
                maxFrog=max(++frog,maxFrog);
            }
            else if(--cnt[x-1]<0) return -1;
            else if(x == 4) --frog;
        }
        return (frog==0)? maxFrog:-1;
    }
};