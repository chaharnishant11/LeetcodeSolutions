class Solution {
public:
    int longestOnes(vector<int>& A, int k) {
        int i=0,j;
        for(j=0;j<A.size();j++){
            if(A[j]==0) k--;
            if(k<0 && A[i++]==0) k++;
        }
        return j-i;
    }
};