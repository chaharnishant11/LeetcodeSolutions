class Solution {
public:
    int rangeBitwiseAnd(int a, int b) {
       while(a < b){ 
            b -= (b & -b); 
        } 
        return b;
    }
};