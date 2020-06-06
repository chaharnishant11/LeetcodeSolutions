class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n=preorder.size();
        if(n==0) return true;
        preorder+=',';
        int c=1;
        for(int i=0;i<=n;i++){
            if(preorder[i]==',') continue;
            c--;
            int j=i;
            while(i<preorder.size() && preorder[i]!=',')i++;
            if(c<0) return false;
            if(preorder.substr(j,i-j)!="#") c+=2;
        }
        return c==0;
    }
};