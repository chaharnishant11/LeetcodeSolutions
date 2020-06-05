class Solution {
public:
    bool isRectangleOverlap(int A, int B, int C, int D, int E, int F, int G, int H) {  
        if(D<=F || H<=B)return false;
        else if(C<=E || G<=A)return false;
        else return true;
    }
    
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int ar1=abs(G-E)*abs(H-F);
        int ar2=abs(C-A)*abs(D-B);
        if((E>=A&&E<=C&&G>=A&&G<=C&&F>=B&&F<=D&&H>=B&&H<=D)||
           (A>=E&&C<=G&&B>=F&&B<=H&&C>=E&&C<=G&&D>=F&&D<=H)){
            return max(ar1,ar2);
        }
        if(isRectangleOverlap(A,B,C,D,E,F,G,H)){
            int ar3=abs(min(G,C)-max(A,E))*abs(min(H,D)-max(B,F));
            return ar1+ar2-ar3;
        }
        else return ar1+ar2;
    }
};