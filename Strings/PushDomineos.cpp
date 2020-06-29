class Solution {
public:
    string pushDominoes(string d) {
        int n=d.size();
        int left[n];
        int right[n];
        memset(left,0,sizeof(left));
        memset(right,0,sizeof(right));
        int force=0;
        for(int i=0;i<n;i++){
            if(d[i]=='R') force=n;
            else if(d[i]=='L') force=0;
            else force=max(force-1,0);
            right[i]+=force;
        }
        force=0;
        for(int i=n-1;i>=0;i--){
            if(d[i]=='L') force=n;
            else if(d[i]=='R') force=0;
            else force=max(force-1,0);
            right[i]-=force;
        }
        string out="";
        for(int i=0;i<n;i++){
            if(right[i]>0) out += 'R';
            else if(right[i]<0) out += 'L';
            else out+='.';
        }
        return out;
    }
};