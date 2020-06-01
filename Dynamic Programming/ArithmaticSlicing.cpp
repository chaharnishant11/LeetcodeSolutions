class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3) return 0;
        int dp=0;
        if (A[2]-A[1] == A[1]-A[0]) dp = 1;
        int result = dp;
        for (int i = 3; i < n; ++i) {
            if (A[i]-A[i-1] == A[i-1]-A[i-2]) 
                dp = dp + 1;
            else dp=0;
            result += dp;
        }
        return result;
    }
};